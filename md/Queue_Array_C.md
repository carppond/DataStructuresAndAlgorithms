## 队列的数组实现

### .h

```
#include <stdio.h>

#pragma mark - 队列的数组实现
typedef struct QueueArrayRecord *ArrayQueue;
typedef int ElementType;

// 队列是否为空
int Arr_IsImpty(ArrayQueue Q);
// 队列是否已经满了
int Arr_IsFull(ArrayQueue Q);
// 初始化一个队列
ArrayQueue Arr_CreateQueue(int MaxElements);
// 释放队列
void Arr_DisposeQueue(ArrayQueue Q);
// 清空队列
void Arr_MakeEmpty(ArrayQueue Q);
// 入队列
void Arr_Enqueue(ElementType X, ArrayQueue Q);
// 出队列
void Arr_Dequeue(ArrayQueue Q);
// 返回队列头元素
ElementType Arr_Front(ArrayQueue Q);
// 返回队列头元素,并且释放队列头元素
ElementType Arr_FrontAndEnqueue(ArrayQueue Q);

struct QueueArrayRecord {
    int Capacity;   // 容量
    int Front;      // 队头: 队列第一个元素的位置
    int Rear;       // 队尾: 队列最后一个元素的位置
    int Size;       // 队列大小
    ElementType *Array;
};
```

### .c

```
#include "Queue.h"
#include <malloc/_malloc.h>

#pragma mark - 队列的数组实现
// 队列是否为空
int Arr_IsImpty(ArrayQueue Q) {
    return Q->Size == 0;
}

// 队列是否已经满了
int Arr_IsFull(ArrayQueue Q) {
    return Q->Size == Q->Capacity;
}

// 初始化一个队列
ArrayQueue Arr_CreateQueue(int MaxElements) {
    ArrayQueue retQ = malloc(sizeof(struct QueueArrayRecord));
    if (retQ == NULL) {
        printf("Error! Out of memory! \n");
        return NULL;
    }
    retQ->Array = (ElementType *)malloc(sizeof(ElementType) * (MaxElements + 1));
    if (retQ->Array == NULL) {
        printf("Error! Out of memory! \n");
        free(retQ);
        return NULL;
    }
    retQ->Capacity = MaxElements;
    retQ->Size = 0;
    retQ->Front = retQ->Rear = 0;
    return retQ;
}

// 释放队列
void Arr_DisposeQueue(ArrayQueue Q) {
    if (Q) {
        free(Q->Array);
        free(Q);
    }
}

// 清空队列
void Arr_MakeEmpty(ArrayQueue Q) {
    Q->Rear = Q->Front;
    Q->Size = 0;
}

// 入队列
void Arr_Enqueue(ElementType X, ArrayQueue Q) {
    int t;
    if (Arr_IsFull(Q)) {
        printf("Error! The queue is full! \n");
        return;
    }
    // Q->Capacity + 1 目的是为了取余正好为 0 的现象
    t = (Q->Rear + 1) % (Q->Capacity + 1);
    Q->Array[t] = X;
    Q->Rear = t;
    Q->Size += 1;
}

// 出队列
void Arr_Dequeue(ArrayQueue Q) {
    if (Arr_IsImpty(Q)) {
        printf("Error! Empty queue! \n");
        return;
    }
    Q->Front = (Q->Front + 1) % (Q->Capacity + 1);
    Q->Size -= 1;
    if (Q->Capacity == Q->Front && Q->Size == 0) {
        Q->Front = 0;
    }
}

// 返回队列头元素
ElementType Arr_Front(ArrayQueue Q) {
    if (Arr_IsImpty(Q)) {
        printf("Error! Empty queue! \n");
        return 0;
    }
    ElementType ret = (Q->Array)[Q->Front];
    return ret;
}

// 返回队列头元素,并且释放队列头元素
ElementType Arr_FrontAndEnqueue(ArrayQueue Q) {
    if (Arr_IsImpty(Q)) {
        printf("Error! Empty queue! \n");
        return 0;
    }
    ElementType ret = (Q->Array)[Q->Front];
    Q->Front = (Q->Front + 1) % (Q->Capacity + 1);
    Q->Size -= 1;
    return ret;
}
```


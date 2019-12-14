//
//  Queue.c
//  Queue
//
//  Created by lcf on 2019/12/14.
//  Copyright © 2019 lcf. All rights reserved.
//

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


#pragma mark - 队列的指针实现

// 队列是否为空
int IsImpty(Queue Q) {
    return Q->Front == Q->Rear;
}

// 初始化一个队列
Queue CreateQueue(void) {
    Queue Q = (Queue)malloc(sizeof(struct Node));
    if (Q == NULL) {
        printf("Error! Out of space");
        return NULL;
    }
    
    Q->Front = Q->Rear = (QueuePtr)malloc(sizeof(struct QueueNode));
    if (Q->Front == NULL) {
        printf("Error! Out of space");
        return NULL;
    }
    Q->Front->Next = NULL;
    return Q;
}

// 释放队列
void DisposeQueue(Queue Q) {
    if (IsImpty(Q)) {
        printf("Error! Empty queue. \n");
        return;
    }
    while (Q->Front != NULL) {
        Q->Rear = Q->Front->Next;
        free(Q->Front);
        Q->Front = Q->Rear;
    }
}

// 清空队列
void MakeEmpty(Queue Q) {
    if (IsImpty(Q)) {
        printf("Error! Empty queue. \n");
        return;
    }
    while (IsImpty(Q)) {
        Dequeue(Q);
    }
}

// 入队列
void Enqueue(ElementType X, Queue Q) {
    QueuePtr  P = (QueuePtr)malloc(sizeof(struct QueueNode));
    if (P == NULL) {
        printf("Error! Out of space");
        return;
    }
    P->Next = NULL;
    P->elem = X;
    // 队列的队尾指向 P
    Q->Rear->Next = P;
    // 设置队列的队尾
    Q->Rear = P;
    printf("==%d=入队了==",X);
}

// 出队列
void Dequeue(Queue Q) {
    if (IsImpty(Q)) {
        printf("Error! Empty queue. \n");
        return;
    }
    QueuePtr P = Q->Front->Next;
    Q->Front->Next = P->Next;
    if (Q->Rear == P) { //判断队列中是否只有一个元素
        Q->Rear = Q->Front;
    }
    free(P);
}

// 返回队列头元素
Element Front(Queue Q) {
    if (Q->Front->Next == NULL) {
        return -1;
    }
    return Q->Front->Next->elem;
}


// 返回队列头元素,并且释放队列头元素
Element FrontAndEnqueue(Queue Q) {
    if (IsImpty(Q)) {
        printf("Error! Empty queue. \n");
        return 0;
    }
    Element X = Front(Q);
    Dequeue(Q);
    return X;
}

// 打印队列
void PrintQueue(Queue Q) {
    if (IsImpty(Q)) {
        printf("Error! Empty queue. \n");
        return;
    }
    QueuePtr P = Q->Front;
    while (P != Q->Rear) {
        P = P->Next;
        printf("element = %d\n",P->elem);
    }
}

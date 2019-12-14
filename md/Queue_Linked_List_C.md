## 队列的链表实现

### .h

```
#pragma mark - 队列的指针实现
struct QueueNode;
struct Node;
typedef struct QueueNode *QueuePtr;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;
typedef int Element;

// 队列是否为空
int IsImpty(Queue Q);
// 初始化一个队列
Queue CreateQueue(void);
// 释放队列
void DisposeQueue(Queue Q);
// 清空队列
void MakeEmpty(Queue Q);
// 入队列
void Enqueue(ElementType X, Queue Q);
// 出队列
void Dequeue(Queue Q);
// 返回队列头元素
Element Front(Queue Q);
// 返回队列头元素,并且释放队列头元素
Element FrontAndEnqueue(Queue Q);
// 打印队列
void PrintQueue(Queue Q);

struct QueueNode {
    Element elem;
    QueuePtr Next;
};

struct Node {
    QueuePtr Front; // 队列头
    QueuePtr Rear;  // 队列尾
};

```



### .c

```
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
        Q->Rear = Q->Rear;
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

```


//
//  LeetCode_641_0198.c
//  LeetCode-week-01
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 cf. All rights reserved.
//

#include "LeetCode_641_0198.h"
#include <malloc/_malloc.h>
#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
struct Node {
    int element;
    PtrToNode Next,Previous;
};

typedef struct {
    PtrToNode Front;
    PtrToNode Rear;
    
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */

MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *Q = (MyCircularDeque *)malloc(sizeof(MyCircularDeque));
    if (Q == NULL) {
        printf("Error! Out of space");
        return NULL;
    }
    Q->Front = Q->Rear = (PtrToNode)malloc(sizeof(struct Node));
    if (Q->Front == NULL) {
        printf("Error! Out of space");
        return NULL;
    }
    Q->Front->Next = NULL;
    Q->Front->Previous = NULL;
    return Q;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    PtrToNode P = (PtrToNode)malloc(sizeof(struct Node));
    if (P == NULL) {
        printf("Error! Out of space");
        return false;
    }
    P->element = value;
    P->Previous = obj->Front;
    // 空队列
    if (obj->Front == obj->Rear) {
        obj->Rear = P;
        P->Next = NULL;
    }
    else {
        P->Next = obj->Front->Next;
        obj->Front->Next->Previous = P;
    }
    obj->Front->Next = P;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    PtrToNode P = (PtrToNode)malloc(sizeof(struct Node));
    if (P == NULL) {
        printf("Error! Out of space");
        return false;
    }
    P->element = value;
    if (obj->Front == obj->Rear) {
        obj->Front->Next = P;
        P->Previous = obj->Front;
        obj->Rear = P;
        return true;
    }
    P->Next = NULL;
    obj->Rear->Next = P;
    P->Previous = obj->Rear;
    obj->Rear = P;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    PtrToNode P;
    if (obj->Front == obj->Rear) {
        printf("Error! Empty queue");
        return false;
    }
    P = obj->Front->Next;
    // 只有最后一个节点
    if (obj->Front->Next == obj->Rear) {
        obj->Front->Next = NULL;
        obj->Rear = obj->Front;
    }
    else {
        P->Next->Previous = obj->Front;
        obj->Front->Next = P->Next;
    }
    free(P);
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    PtrToNode P;
    if (obj->Front == obj->Rear) {
        printf("Error! Empty queue");
        return false;
    }
    P = obj->Rear;
    obj->Rear = P->Previous;
    obj->Rear->Next = NULL;
    free(P);
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    PtrToNode P;
    if (obj->Front == obj->Rear) {
        printf("Error! Empty queue");
        return 0;
    }
    P = obj->Front->Next;
    return P->element;
}

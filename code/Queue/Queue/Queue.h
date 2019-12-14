//
//  Queue.h
//  Queue
//
//  Created by lcf on 2019/12/14.
//  Copyright © 2019 lcf. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

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

#endif /* Queue_h */

//
//  Stack.h
//  Stack
//
//  Created by lcf on 2019/12/13.
//  Copyright © 2019 lcf. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

#pragma mark - 栈的指针实现

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

typedef int  Elenment;

// 是否为空栈
int IsEmpty(Stack S);
// 创建一个栈
Stack CreateStack(void);
// 释放栈
void DisposeStack(Stack S);
// 清空栈
void MakeEmpty(Stack S);
// 入栈
void Push(Elenment X, Stack S);
// 出栈
void Pop(Stack S);
// 得到栈顶元素
Elenment Top(Stack S);

struct Node {
    Elenment element;
    PtrToNode Next;
};

#pragma mark - 栈的数组实现

struct StackRecord;
typedef struct StackRecord *StackK;
typedef int ElenmentType;

// 是否为空栈
int _IsEmpty(StackK S);
// 栈是否满了
int _IsFull(StackK S);
// 创建一个栈
StackK _CreateStack(int maxElements);
// 销毁栈
void _DisposeStack(StackK S);
// 清空栈
void _MakeEmpty(StackK S);
// 入栈
void _Push(ElenmentType X,StackK S);
// 栈顶元素
ElenmentType _Top(StackK S);
// 出栈
void _Pop(StackK S);
// 获取栈顶元素并出栈
ElenmentType _TopAndPop(StackK S);

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord {
    int Capacity;   // 容量
    int TopOfStack;
    ElenmentType *Array;
};
#endif /* Stack_h */

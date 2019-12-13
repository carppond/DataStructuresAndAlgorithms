//
//  Stack.c
//  Stack
//
//  Created by lcf on 2019/12/13.
//  Copyright © 2019 lcf. All rights reserved.
//

#include "Stack.h"
#include <malloc/_malloc.h>

#pragma mark - 栈的指针实现
// 是否为空栈
int IsEmpty(Stack S) {
    return S->Next == NULL;
}

// 创建一个栈
Stack CreateStack(void) {
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("栈的初始化出错");
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

// 释放栈
void DisposeStack(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty Stack");
        return;
    }
    while (S->Next) {
        Stack TmpCell = S->Next;
        free(S);
        S = TmpCell;
    }
}

// 清空栈
void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Must use `CreateStack` Frist");
    }
    else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}
// 入栈
void Push(Elenment X, Stack S) {
    Stack tmp;
    tmp = malloc(sizeof(struct Node));
    if (tmp == NULL) {
        printf("Out of Space");
    }
    else {
        tmp->element = X;
        tmp->Next = S->Next;
        S->Next = tmp;
    }
}

// 出栈
void Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty Stack");
        return;
    }
    Stack TmpCell;
    TmpCell = S->Next;
    S->Next = S->Next->Next;
    free(TmpCell);
}

// 得到栈顶元素
Elenment Top(Stack S) {
    if (IsEmpty(S)) {
        printf("Empty Stack");
        return 0;
    }
    Stack TmpCell = S->Next;
    return TmpCell->element;
}

#pragma mark - 栈的数组实现

// 是否为空栈
int _IsEmpty(StackK S) {
    return S->TopOfStack == EmptyTOS;
}

// 栈是否满了
int _IsFull(StackK S) {
    return S->TopOfStack >= S->Capacity;
}

// 创建一个栈
StackK _CreateStack(int maxElements) {
    StackK S;
    if (maxElements < MinStackSize) {
        printf("Stack space is too small");
        return NULL;
    }
    S = malloc(sizeof(ElenmentType) * maxElements);
    if (S == NULL) {
        printf("Out of space");
        return NULL;
    }
    S->Array = malloc(sizeof(ElenmentType) *maxElements);
    if (S->Array == NULL) {
        printf("Out of space");
        return NULL;
    }
    S->Capacity = maxElements;
    _MakeEmpty(S);
    return S;
}
// 销毁栈
void _DisposeStack(StackK S) {
    
    if (S) {
        free(S->Array);
        free(S);
    }
}

// 清空栈
void _MakeEmpty(StackK S) {
    S->TopOfStack = EmptyTOS;
}
// 入栈
void _Push(ElenmentType X,StackK S) {
    if (_IsFull(S)) {
        printf("Full stack");
        return;
    }
    S->Array[++(S->TopOfStack)] = X;
}

// 栈顶元素
ElenmentType _Top(StackK S) {
    if (_IsEmpty(S)) {
        printf("Empty Stack");
        return 0;
    }
    return S->Array[S->TopOfStack];
}

// 出栈
void _Pop(StackK S) {
    if (_IsEmpty(S)) {
       printf("Empty Stack");
       return;
    }
    (S->TopOfStack)--;
}

// 获取栈顶元素并出栈
ElenmentType _TopAndPop(StackK S) {
    if (_IsEmpty(S)) {
        printf("Empty Stack");
        return 0;
    }
    return (S->Array)[(S->TopOfStack)--];
}


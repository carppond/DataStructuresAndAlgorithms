

## 栈的指针实现

### .h

```
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
```



### .c

```
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

```




## 栈的数组实现

### .h

```
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
```



### .c

```
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
```


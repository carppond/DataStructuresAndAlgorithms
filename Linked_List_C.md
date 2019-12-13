链表

.h

```
#ifndef LinkedList_h
#define LinkedList_h

#include <stdio.h>

struct Node;
typedef struct Node * ptrToNode;
typedef ptrToNode List;
typedef ptrToNode Position;
typedef int Element;

// 初始化一个空的线性表
List MakeEmpty(List L);
// 判断是否为空
int IsEmpty(List L);
// 判断是否是最后一个元素
int isLast(Position P, List L);
// 在线性表 L 中查找 x 第一次出现的位置
Position Find(Element x, List L);
// 删除指定的元素
void Delete(Element x, List L);
// 寻找前驱元素并返回
Position FindPrevious(Element x, List L);
// 在位置 P 插入一个新的元素
void Insert(Element x, List L, Position P);
// 删除整个表
void DeleteList(List L);
// 寻找头结点
Position Header(List L);
// 寻找第一个
Position Frist(List L);


struct Node {
    Element data;
    Position Next;
};

#endif 
```

.c

```
#include <stdlib.h> 
#include <malloc/malloc.h>

// 初始化一个空的线性表
List MakeEmpty() {
    List Ptrl;
    Ptrl = malloc(sizeof(struct Node));
    Ptrl->data = 0;
    Ptrl->Next = NULL;
    return Ptrl;
}

// 判断是否为空
int IsEmpty(List L) {
    return L->Next == NULL;
}

// 判断是否是最后一个元素
int isLast(Position P, List L) {
    return P->Next == NULL;
}

// 在线性表 L 中查找 x 第一次出现的位置
Position Find(Element x, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->data != x) {
        P = P->Next;
    }
    return P;
}

// 删除指定的元素
void Delete(Element x, List L) {
    Position P, TmpCell;
    P = FindPrevious(x, L);
    if (!isLast(P, L)) {
        TmpCell = P->Next; // TmpCell：x 所在节点
        P->Next = TmpCell->Next; // 指向 TmpCell 的下一个节点
        free(TmpCell);
    }
    
}

//  寻找前驱元素并返回
Position FindPrevious(Element x, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->data != x) {
        P = P->Next;
    }
    return P;
}

// 在位置 P 插入一个新的元素
void Insert(Element x, List L, Position P) {
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("Out of space");
    }
    TmpCell->data = x;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

// 删除链表
void DeleteList(List L) {
    Position P, Tmp;
    P = L->Next;
    while (P->Next != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
    L->Next = NULL;
}
// 获取链表头
Position Header(List L) {
    return L;
}
// 获取第一个节点
Position Frist(List L) {
    return L->Next;
}

```




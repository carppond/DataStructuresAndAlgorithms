//
//  LinkedList.c
//  链表-01
//
//  Created by lcf on 2019/12/9.
//  Copyright © 2019 lcf. All rights reserved.
//

#include "LinkedList.h"
#include <stdlib.h> 
#include <malloc/malloc.h>

List MakeEmpty() {
    List Ptrl;
    Ptrl = malloc(sizeof(struct Node));
    Ptrl->data = 0;
    Ptrl->Next = NULL;
    return Ptrl;
}

int IsEmpty(List L) {
    return L->Next == NULL;
}

int isLast(Position P, List L) {
    return P->Next == NULL;
}
Position Find(Element x, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->data != x) {
        P = P->Next;
    }
    return P;
}
void Delete(Element x, List L) {
    Position P, TmpCell;
    P = FindPrevious(x, L);
    if (!isLast(P, L)) {
        TmpCell = P->Next; // TmpCell：x 所在节点
        P->Next = TmpCell->Next; // 指向 TmpCell 的下一个节点
        free(TmpCell);
    }
    
}
Position FindPrevious(Element x, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->data != x) {
        P = P->Next;
    }
    return P;
}
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

Position Header(List L) {
    return L;
}

Position Frist(List L) {
    return L->Next;
}

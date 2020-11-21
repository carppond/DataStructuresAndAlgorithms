//
//  SinglyLinkedList.c
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/19.
//

#include "SinglyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>
#include <syslog.h>

List InitList(void) {
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Node));
    if (PtrL == NULL) {
        syslog(LOG_ERR, "InitList Failure");
    }
    PtrL->elem = 0;
    PtrL->Next = NULL;
    return PtrL;
}

int IsEmpty(List L) {
    return L->Next == NULL;
}

int IsLast(List L, Position P) {
    return P->Next == NULL;
}

Position Find(Elementype X, List L) {
    Position P;
    P = L->Next;
    while (P->Next != NULL && P ->elem != X) {
        P = P->Next;
    }
    return P;
}

bool Delete(Elementype X, List L) {
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (IsLast(L, P)) {
        return false;
    }
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
    return true;
}

Position FindPrevious(Elementype X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->elem != X) {
        P = P->Next;
    }
    return P;
}

bool Insert(Elementype X,List L, Position P) {
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        syslog(LOG_ERR, "malloc Node Failure");
        return false;
    }
    TmpCell->elem = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
    return true;
}


bool DeleteList(List L) {
    Position P, TmpCell;
    P = L->Next;
    while (P->Next != NULL) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
    L->Next = NULL;
    L->elem = 0;
    return true;
}

Position Header(List L) {
    return L;
}

Position Frist(List L) {
    return L->Next;
}




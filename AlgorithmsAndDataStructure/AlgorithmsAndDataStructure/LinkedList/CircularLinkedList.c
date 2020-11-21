//
//  CircularLinkedList.c
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/19.
//

#include "CircularLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc/malloc.h>
#include <syslog.h>

List Circular_InitList(void) {
    List PtrL;
    PtrL = (List)malloc(sizeof(struct Node));
    if (PtrL == NULL) {
        syslog(LOG_ERR, "InitList Failure");
    }
    PtrL->elem = 0;
    PtrL->Next = PtrL;
    return PtrL;
}

int Circular_IsEmpty(List L) {
    return L->Next == L;
}

int Circular_IsLast(List L, Position P) {
    return P->Next == L;
}

Position Circular_Find(Elementype X, List L) {
    Position P;
    P = L->Next;
    while (P->Next != NULL && P ->elem != X && P->Next != L) {
        P = P->Next;
    }
    return P;
}

bool Circular_Delete(Elementype X, List L) {
    Position P, TmpCell;
    P = Circular_FindPrevious(X, L);
    if (Circular_IsLast(L, P)) {
        return false;
    }
    TmpCell = P->Next;
    P->Next = TmpCell->Next;
    free(TmpCell);
    return true;
}

Position Circular_FindPrevious(Elementype X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->elem != X && P->Next != L) {
        P = P->Next;
    }
    return P;
}

bool Circular_Insert(Elementype X,List L, Position P) {
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


bool Circular_DeleteList(List L) {
    Position P, TmpCell;
    P = L->Next;
    while (P->Next != NULL && P->Next != L) {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
    L->Next = L;
    L->elem = 0;
    return true;
}

Position Circular_Header(List L) {
    return L;
}

Position Circular_Frist(List L) {
    return L->Next;
}




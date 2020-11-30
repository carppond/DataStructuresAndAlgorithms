//
//  StackLinkedList.c
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/30.
//

#include "StackLinkedList.h"
#include <malloc/_malloc.h>


int Stack_IsEmpty(Stack S) {
    
    return S->Next == NULL;
}

Stack Stack_CreateStack(void) {
    Stack S;
    S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Out of Spac");
    }
    S->Next = NULL;
    S->elem = 0;
    return S;
}


void Stack_DisposeStack(Stack S) {
    Stack_MakeEmpty(S);
    free(S);
}

void Stack_MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("S is NULL, Must use Stack_CreateStack first");
        return;
    }
    while (!Stack_IsEmpty(S)) {
        Stack_Pop(S);
    }
}

void Stack_Push(Elem X, Stack S) {
    
    PtrToNode CurCell;
    CurCell = (PtrToNode)malloc(sizeof(struct Node));
    if (CurCell == NULL) {
        printf("Out of Spac");
        return;
    }
    CurCell->elem = X;
    CurCell->Next = S->Next;
    S->Next = CurCell;
}

void Stack_Pop(Stack S) {
    PtrToNode FirstCell;
    if (Stack_IsEmpty(S)) {
        printf("Stack is Empty");
        return;
    }
    FirstCell = S->Next;
    S->Next = FirstCell->Next;
    free(FirstCell);
}

Elem Stack_Top(Stack S) {
    return S->Next;
}

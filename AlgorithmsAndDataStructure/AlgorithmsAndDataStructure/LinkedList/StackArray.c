//
//  StackArray.c
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/30.
//

#include "StackArray.h"
#include <malloc/_malloc.h>
#include <stdlib.h>

struct StackRecord {
    int capacity;
    int TopOfStack;
    ElementType *Array;
};


int StackArray_IsEmpty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

Stack StackArray_CreateStack(int MaxElems) {
    if (MaxElems < MinStackSize) {
        printf("Stack size is too small");
        return NULL;
    }
    Stack S;
    S = (Stack)malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        printf("Out of Spac");
        return NULL;
    }
    S->Array = malloc(sizeof(Elem) * MaxElems);
    if (S->Array == NULL) {
        printf("Out of Spac");
        return NULL;
    }
    S->capacity = MaxElems;
    StackArray_MakeEmpty(S);
    return S;
}

void StackArray_DisposeStack(Stack S) {
    if (S == NULL) {
        return;
    }
    free(S->Array);
    free(S);
}

void StackArray_MakeEmpty(Stack S) {
    S->TopOfStack = EmptyTOS;
}

void StackArray_Push(Elem X, Stack S) {
    if (S->TopOfStack == S->capacity - 1) {
        printf("Stack is Full!!");
        return;
    }
    S->TopOfStack += 1;
    S->Array[S->TopOfStack] = X;
}

void StackArray_Pop(Stack S) {
    if (StackArray_IsEmpty(S)) {
        printf("Stack is Empty!!");
        return;
    }
//    ElementType *x = NULL;
//    *x = S->Array[S->TopOfStack];
//    free(*x);
    S->TopOfStack -= 1;
}

ElementType StackArray_Top(Stack S) {
    if (StackArray_IsEmpty(S)) {
        printf("Stack is Empty!!");
        return 0;
    }
    return S->Array[S->TopOfStack];
}

ElementType StackArray_TopAndPop(Stack S) {
    if (StackArray_IsEmpty(S)) {
        printf("Stack is Empty!!");
        return 0;
    }
    S->TopOfStack -= 1;
    return S->Array[S->TopOfStack];
}

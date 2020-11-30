//
//  StackArray.h
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/30.
//

#ifndef StackArray_h
#define StackArray_h

#include <stdio.h>

struct StackRecord;
typedef struct StackRecord *Stack;
typedef int Elem;
typedef int ElementType;

int StackArray_IsEmpty(Stack S);
Stack StackArray_CreateStack(int MaxElems);
void StackArray_DisposeStack(Stack S);
void StackArray_MakeEmpty(Stack S);
void StackArray_Push(Elem X, Stack S);
void StackArray_Pop(Stack S);
ElementType StackArray_Top(Stack S);
ElementType StackArray_TopAndPop(Stack S);


#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

#endif /* StackArray_h */

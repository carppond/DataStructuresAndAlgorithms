//
//  StackLinkedList.h
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/30.
//
/*!
 *  @brief  链表实现栈
 */

#ifndef StackLinkedList_h
#define StackLinkedList_h

#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int Elem;

int Stack_IsEmpty(Stack S);
Stack Stack_CreateStack(void);
void Stack_DisposeStack(Stack S);
void Stack_MakeEmpty(Stack S);
void Stack_Push(Elem X, Stack S);
void Stack_Pop(Stack S);
Elem Stack_Top(Stack S);


struct Node {
    Elem elem;
    PtrToNode Next;
};

#endif /* StackLinkedList_h */

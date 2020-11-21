//
//  CircularLinkedList.h
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/19.
//

/*!
 *  @brief  单向循环链表
 */

#ifndef CircularLinkedList_h
#define CircularLinkedList_h

#include <stdio.h>

#include <stdio.h>
#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int Elementype;


List Circular_InitList(void);
int Circular_IsEmpty(List L);
int Circular_IsLast(List L, Position P);
Position Circular_Find(Elementype X, List L);
bool Circular_Delete(Elementype X, List L);
Position Circular_FindPrevious(Elementype X, List L);
bool Circular_Insert(Elementype X,List L, Position P);
bool Circular_DeleteList(List L);
Position Circular_Header(List L);
Position Circular_Frist(List L);


struct Node {
    Elementype elem;
    Position Next;
};


#endif /* CircularLinkedList_h */

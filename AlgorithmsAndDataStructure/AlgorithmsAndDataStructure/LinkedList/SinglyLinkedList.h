//
//  SinglyLinkedList.h
//  AlgorithmsAndDataStructure
//
//  Created by lcf on 2020/11/19.
//

#ifndef SinglyLinkedList_h
#define SinglyLinkedList_h

#include <stdio.h>
#include <stdbool.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int Elementype;


List InitList(void);
int IsEmpty(List L);
int IsLast(List L, Position P);
Position Find(Elementype X, List L);
bool Delete(Elementype X, List L);
Position FindPrevious(Elementype X, List L);
bool Insert(Elementype X,List L, Position P);
bool DeleteList(List L);
Position Header(List L);
Position Frist(List L);


struct Node {
    Elementype elem;
    Position Next;
};

#endif /* SinglyLinkedList_h */

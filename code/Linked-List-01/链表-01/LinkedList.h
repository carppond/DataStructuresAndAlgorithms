//
//  LinkedList.h
//  链表-01
//
//  Created by lcf on 2019/12/9.
//  Copyright © 2019 lcf. All rights reserved.
//

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

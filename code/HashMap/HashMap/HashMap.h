//
//  HashMap.h
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//  分离链接法

#ifndef HashMap_h
#define HashMap_h

#include <stdio.h>

struct ListNode;
typedef struct ListNode *Position;
typedef Position List;

struct HashTbl;
typedef struct HashTbl *HashTable;

typedef int ElementType;
typedef unsigned int Index;

// 初始化哈希表
HashTable InitializeTable(int TableSize);
// 销毁哈希表
void DestroyTable(HashTable H);
// 通过 key 查找对应的表
Position Find(ElementType Key, HashTable H);
// 插入一个元素
void Insert(ElementType Key, HashTable H);
//
ElementType Retrieve(Position P);

// 哈希表的最小空间
#define MinTableSize 5

struct ListNode {
    ElementType Element;
    Position    Next;
};

struct HashTbl {
    int   TableSize;
    List *TheLists; // 链表数组
};

#endif /* HashMap_h */

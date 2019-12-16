//
//  HashMap2.h
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//  开放定址法:  平方探测法

#ifndef HashMap2_h
#define HashMap2_h

#include <stdio.h>

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

typedef struct HashEntry Cell;

typedef int ElementType;

// 初始化散列表
HashTable InitializeTable(int TableSize);
// 销毁散列表
void DestroyTable(HashTable H);
// 根据 key 查找对象位置
Position Find(ElementType key, HashTable H);
// 插入一个元素
void Insert(ElementType key, HashTable H);
//
ElementType Retrieve(Position P, HashTable H);
// 重新 hash
HashTable Rehash(HashTable H);


enum KindOfEntry{Legitimate, Empty, Deleted};

struct HashEntry {
    ElementType element;
    enum KindOfEntry Info;
};

struct HashTbl {
    int TableSize;
    Cell *TheCells;
};

#endif /* HashMap2_h */

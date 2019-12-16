//
//  HashMap2.c
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//

#include "HashMap2.h"
#include <stdlib.h>

#define MinTableSize (10)

static int
NextPrime( int N )
{
    int i;

    if( N % 2 == 0 )
        N++;
    for( ; ; N += 2 )
    {
        for( i = 3; i * i <= N; i += 2 )
            if( N % i == 0 )
                goto ContOuter;  /* Sorry about this! */
        return N;
      ContOuter: ;
    }
}

Index
Hash( ElementType Key, int TableSize )
{
    return Key % TableSize;
}

// 初始化散列表
HashTable
InitializeTable(int TableSize) {
    
    HashTable H;
    int i;
    if (TableSize < MinTableSize) {
        printf("Table size too small" );
        return NULL;
    }
    // 哈希表分配内存
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        printf("Out of space");
        return NULL;
    }
    H->TableSize = NextPrime(TableSize);
    
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if( H->TheCells == NULL ) {
        printf("Out of space");
        return NULL;
    }
    
    for (i = 0; i < H->TableSize; ++i) {
        H->TheCells[i].Info = Empty;
    }
    return H;
}
// 销毁散列表
void DestroyTable(HashTable H);
// 根据 key 查找对象位置
Position
Find(ElementType key, HashTable H) {
        
    Position CurrentPos;
    int collisionNum = 0; // 碰撞数
    CurrentPos = Hash(key, H->TableSize);
    while (H->TheCells[CurrentPos].Info != Empty &&
           H->TheCells[CurrentPos].element != key) {
        CurrentPos += 2 * ++collisionNum -1;
        if (CurrentPos >= H->TableSize) {
            CurrentPos -= H->TableSize;
        }
    }
    return CurrentPos;
}

// 插入一个元素
void
Insert(ElementType key, HashTable H) {
    Position Pos;
    Pos = Find(key, H);
    if (H->TheCells[Pos].Info != Legitimate) {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].element = key; // Probably need strcpy
    }
}
//
ElementType
Retrieve(Position P, HashTable H) {
    return H->TheCells[P].element;
}

// 重新 hash
HashTable Rehash(HashTable H) {
    int i, OldSize;
    Cell *OldCells;
    
    OldSize = H->TableSize;
    OldCells = H->TheCells;
    
    H = InitializeTable(2 * OldSize);
    for (i = 0; i < OldSize; ++i) {
        if (OldCells[i].Info == Legitimate) {
            Insert(OldCells[i].element, H);
        }
    }
    free(OldCells);
    return H;
}


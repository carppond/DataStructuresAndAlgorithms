//
//  HashMap.c
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//  分离链接法

#include "HashMap.h"
#include <malloc/_malloc.h>

/* 返回一个素数,例如 N >= 10 */
static int
NextPrime( int N ) {
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

// 整数的哈希函数(散列函数)
Index
Hash( ElementType Key, int TableSize ) {
    
  return Key % TableSize;
};

// 初始化哈希表
HashTable
InitializeTable(int TableSize) {
    
    HashTable H;
    if (TableSize < MinTableSize) {
        printf("Table size too small!");
        return NULL;
    }
    // 给哈希表分配内存空间
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL) {
        printf("Out of space");
        return NULL;
    }
    H->TableSize = NextPrime(TableSize);
    // 给链表数组分配内存空间
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) {
        printf("Out of space");
        return NULL;
    }
    // 给链表数组 Headers 分配内存空间
    for (int i = 0; i < TableSize; ++i) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL) {
            printf("Out of space");
            return NULL;
        }
        else {
            H->TheLists[i]->Next = NULL;
        }
    }
    return H;
}

// 通过 key 查找对应的表
// 如果 ElementType 是字符串,就要使用 strcmp 和  strcpy 来进行比较
Position
Find(ElementType Key, HashTable H) {
    Position P;
    List L;
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key) {
        P = P->Next;
    }
    return P;
}

// 插入一个元素
void
Insert(ElementType Key, HashTable H) {
    
    Position P, NewCell;
    List L;
    P = Find(Key, H);
    if (P == NULL) {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL) {
            printf("Out of space");
            return;
        }
        else {
            L = H->TheLists[Hash(Key, H->TableSize)];
            NewCell->Next = L->Next;
            NewCell->Element = Key; // 可能需要 strcpy
            L->Next = NewCell;
        }
    }
}

ElementType
Retrieve(Position P) {
    return P->Element;
}

// 销毁哈希表
void
DestroyTable(HashTable H) {
    int i;
    for (i = 0; i < H->TableSize; ++i) {
        Position P = H->TheLists[i];
        Position Tmp;
        while (P != NULL) {
            Tmp = P->Next;
            free(P);
            P = Tmp;
        }
    }
    free(H->TheLists);
    free(H);
}




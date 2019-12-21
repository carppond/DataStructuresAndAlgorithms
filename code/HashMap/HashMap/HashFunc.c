//
//  HashFunc.c
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//

#include "HashFunc.h"

/*
 把字符串中字符的 ASCII 码加起来
 */
Index
Hash1(const char *key, int TableSize) {
    
    unsigned int HashVal = 0;
    while (*key != '\0') {
        HashVal += *key++;
    }
    return HashVal % TableSize;
}


Index
Hash2(const char *key, int TableSize) {
    
    unsigned int HashVal = key[0] + 27 * key[1] + 729 * key[2];
    return HashVal % TableSize;
}

Index
Hash3(const char *key, int TableSize) {
    
    unsigned int HashVal = 0;
    while (*key != '\0') {
        HashVal = ( HashVal << 5 ) + *key++;
    }
    return HashVal % TableSize;
}

// key的类型为void *，是一个任意类型，上面的哈希函数只针对const char *类型，可以根据实际需要替换成其他。
Index
HashCode(int TableSize, void * key)
{
    // 加锁
    const char * k = (const char *)key;
    
    unsigned long h = 0;
    while (*k) {
        h = (h << 4) + *k++;
        unsigned long g = h & 0xF0000000L;
        if (g) {
            h ^= g >> 24;
        }
        h &= ~g;
    }
    // 解锁
    return h % TableSize;
}


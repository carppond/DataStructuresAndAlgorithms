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


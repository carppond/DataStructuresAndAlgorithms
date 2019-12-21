//
//  HashFunc.h
//  HashMap
//
//  Created by lcf on 2019/12/16.
//  Copyright © 2019 lcf. All rights reserved.
//

#ifndef HashFunc_h
#define HashFunc_h

#include <stdio.h>

typedef unsigned int Index;

// 比较靠谱的
Index HashCode(int TableSize, void * key);
#endif /* HashFunc_h */

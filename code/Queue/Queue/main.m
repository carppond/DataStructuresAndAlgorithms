//
//  main.m
//  Queue
//
//  Created by lcf on 2019/12/14.
//  Copyright © 2019 lcf. All rights reserved.
//
#include "Queue.h"

#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        Queue Q;
        int i;
        Q = CreateQueue();
        for (i =1; i< 13;++i) {
            Enqueue(i, Q);
        }
        while (!IsImpty(Q) && Front(Q) != -1) {
            printf("==%d \n",Front(Q));
            Dequeue(Q);
        }
        printf("==============================\n======================");
        MakeEmpty(Q);
        printf("==%d \n",Front(Q));
        DisposeQueue(Q);
        getchar();
    }
    return 0;
}

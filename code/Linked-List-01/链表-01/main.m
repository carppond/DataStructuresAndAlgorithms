//
//  main.m
//  链表-01
//
//  Created by lcf on 2019/12/9.
//  Copyright © 2019 lcf. All rights reserved.
//

#import <Foundation/Foundation.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *cur;
    cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur = head;
    while (cur != NULL) {
        struct ListNode *frist, *second;
        frist = cur->next;
        second = cur->next->next;
        frist->next = second->next;
        cur->next = second;
        cur->next->next = frist;
        cur = cur->next->next;
    }
    return head;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}

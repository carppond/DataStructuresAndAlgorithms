//
//  main.m
//  LeetCode-week-01
//
//  Created by cf on 2019/12/15.
//  Copyright © 2019 cf. All rights reserved.
//

#import <Foundation/Foundation.h>



void merge11(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    
    int p1 = m - 1;
    int p2 = n - 1;
      // set pointer for nums1
    int p = m + n - 1;

    // while there are still elements to compare
    while ((p1 >= 0) && (p2 >= 0)) {
        // compare two elements from nums1 and nums2
        // and add the largest one in nums1
        nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
    }
    
    for (int i = 0; i < m + n; ++i) {
        printf("=== %d",nums1[i]);
    }
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {2,5,6};
        merge11(nums1, 6, 3, nums2, 3, 3);
        
    }
    return 0;
}

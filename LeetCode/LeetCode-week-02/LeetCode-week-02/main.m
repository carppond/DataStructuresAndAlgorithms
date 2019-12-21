//
//  main.m
//  LeetCode-week-02
//
//  Created by lcf on 2019/12/18.
//  Copyright © 2019 lcf. All rights reserved.
//

#import <Foundation/Foundation.h>
bool aisAnagram(char * s, char * t){
    
    int slen = (int)strlen(s);
    int tlen = (int)strlen(t);
    if (slen != tlen) {
        return false;
    }
    int targets[26] = {0};
    for (int i = 0; i < slen; ++i) {
        targets[s[i] - 'a']++;
        targets[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; ++i) {
        if (targets[i] != 0) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        printf("==%d\n",isAnagram("abc", "edc"));
        char *a = "fafdsfdsf";
        char *t = "dsfdsffaf";
        
        printf("==%d\n\n",aisAnagram(a, t));
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}

/*
 
 ////////////////////// 哈希表 ///////////////////////////////
 https://leetcode-cn.com/problems/valid-anagram/description/           == 1
 https://leetcode-cn.com/problems/group-anagrams/                      ==
 https://leetcode-cn.com/problems/two-sum/description/                 ==
 
 
 ////////////////////// 树-二叉树-二叉搜索树 ////////////////////
 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/       ==
 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/      ==
 https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/      ==
 https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/       ==
 https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/    ==
 
 
////////////////////// 泛型递归-树的递归 ////////////////////
 https://leetcode-cn.com/problems/climbing-stairs/                     ==
 https://leetcode-cn.com/problems/generate-parentheses/                ==
 https://leetcode-cn.com/problems/invert-binary-tree/description/      ==
 https://leetcode-cn.com/problems/validate-binary-search-tree          ==
 https://leetcode-cn.com/problems/maximum-depth-of-binary-tree         ==
 https://leetcode-cn.com/problems/minimum-depth-of-binary-tree         == 
 https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/ ==
 */

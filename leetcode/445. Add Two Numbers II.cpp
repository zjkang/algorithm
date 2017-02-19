/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Add Two Numbers II
 Source:     https://leetcode.com/problems/add-two-numbers-ii/?tab=Description
 Difficulty: Medium
 Tags:       {Linked List}
 Company:    Microsoft, Bloomberg
 
 Notes:
 You are given two non-empty linked lists representing two non-negative integers. 
 The most significant digit comes first and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Follow up:
 What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

 Example:

 Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 8 -> 0 -> 7
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* l1) {
        int len = 0;
        while (l1) {
            l1 = l1->next;
            len++;
        }
        return len;
    }
    
    ListNode* getSum(ListNode* l1, ListNode* l2, int& carry, int diff) {
        if (!l1 || !l2) {
            return NULL;
        }
        ListNode* n1 = NULL;
        int sum = 0;
        if (diff > 0) {
            n1 = getSum(l1->next, l2, carry, diff-1);
            sum = l1->val + carry;
        }
        else {
            n1 = getSum(l1->next, l2->next, carry, 0);
            sum = l1->val + l2->val + carry;            
        }
        ListNode* node = new ListNode(sum % 10);
        node->next = n1;
        carry = sum / 10;
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return l1 ? l1 : l2;
        }
        int len1 = getLength(l1), len2 = getLength(l2);
        if (len2 > len1) {
            swap(l1, l2);
        }
        int carry = 0;
        ListNode* n = getSum(l1, l2, carry, abs(len1 - len2)); // abs
        if (carry) {
            ListNode* res = new ListNode(carry);
            res->next = n;
            return res;
        }
        return n;
    }
};





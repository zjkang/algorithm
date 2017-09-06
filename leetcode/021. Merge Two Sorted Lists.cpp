/*
Author:     Zhengjian Kang
Email:      zhengjian.kang@nyu.edu
Problem:    Merge Two Sorted Lists
Source:     https://leetcode.com/problems/merge-two-sorted-lists/
Tags:       {Linked List}
Company:    Amazon, LinkedIn, Apple, Microsoft

Notes:
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != NULL ? l1 : l2;
        return dummy.next;
    }
};

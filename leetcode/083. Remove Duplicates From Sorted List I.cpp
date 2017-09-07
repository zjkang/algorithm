/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Remove Duplicates from Sorted List
 Source:     https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 Tags:       {Linked List}

 Notes:
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.          
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode *node = cur->next;
                cur->next = node->next;
                delete node;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
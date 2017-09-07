/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Partition List
 Source:     https://leetcode.com/problems/partition-list/
 Difficulty: Medium
 Tags:       {Linked List}, {Two Pointers}

 Notes:
 Given a linked list and a value x, partition it such that all nodes less than x come 
 before nodes greater than or equal to x.
 You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.
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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return NULL;
        ListNode leftDummy(0);
        ListNode rightDummy(0);
        ListNode *left = &leftDummy, *right = &rightDummy;
        while (head) {
            if (head->val < x) {
                left->next = head;
                left = head;
            } else {
                right->next = head;
                right = head;
            }
            head = head->next;
        }
        right->next = NULL;
        left->next = rightDummy.next;
        return leftDummy.next;
    }
};

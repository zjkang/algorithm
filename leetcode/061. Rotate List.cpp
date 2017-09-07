/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Rotate List
 Source:     http://oj.leetcode.com/problems/rotate-list/
 Tags:       {Linked List}, {Two Pointers}

 Notes:
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
 Solution: Notice that k can be larger than the list size (k % list_size).
           This solution traverses the list twice at most.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return NULL;
        ListNode* tail = head;
        int length = 1;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        k = k % length; // edge case: the list rotates more than one round.
        if (k == 0) return head;
        ListNode* cur = head;
        for (int i = 0; i < length - k - 1; i++) {
            cur = cur->next;            
        }
        ListNode* newHead = cur->next;
        cur->next = NULL;
        tail->next = head;
        return newHead;
    }
};
/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Reverse Linked List II
 Source:     https://leetcode.com/problems/reverse-linked-list-ii/
 Difficulty: Medium
 Tags:       {Linked List}
 
 Notes:
 There is no Reverse Linked List I.
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.
 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

 Solution: in-place & one-pass.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;   
        for (int i = 0; i < m - 1; ++i) {
            head = head->next;
        }
        ListNode *cur = head->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = head->next;
            head->next = move;
        }
        return dummy.next;
    }
};
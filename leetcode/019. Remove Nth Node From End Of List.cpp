/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Remove Nth Node From End of List
 Source:     https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 Tags:       {Linked List}, {Two Pointers}

 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution: head---back------front------>NULL
                   |          |
                   ---> n <----
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // corner case: 头结点,使用dummy node
        ListNode dummy(0);
        ListNode* back = &dummy;
        ListNode* front = &dummy;        
        dummy.next = head;
        while (n--) {
            front = front->next;
        }
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode *node = back->next;
        back->next = node->next;
        delete node;
        return dummy.next;
    }
};

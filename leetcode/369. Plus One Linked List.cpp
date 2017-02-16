/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Plus One Linked List
 Source:     https://leetcode.com/problems/plus-one-linked-list/
 Difficulty: Medium
 Tags:       {Linked List}
 Company:    Google
 
 Notes:
 Given a non-negative integer represented as non-empty a singly linked list of digits, 
 plus one to the integer.

 You may assume the integer do not contain any leading zero, except the number 0 itself.

 The digits are stored such that the most significant digit is at the head of the list.

 Example:
 Input:
 1->2->3

 Output:
 1->2->4
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
    ListNode* reverse(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        while (head->next) {
            ListNode* next = head->next;
            head->next = next->next;
            next->next = dummy.next;
            dummy.next = next;
        }
        return dummy.next;
    }

    ListNode* plusOne(ListNode* head) {
        if (!head) return NULL;
        ListNode* r = reverse(head);
        int carry = 1;
        
        ListNode dummy(0);
        dummy.next = r;
        r = &dummy;
        while (r->next) {
            int val = r->next->val;
            r->next->val = (val + carry) % 10;
            carry = (val + carry) / 10;

            if (carry == 0) break;
            r = r->next;
        }
        if (carry == 1) {
            r->next = new ListNode(1);
        }
        return reverse(dummy.next);
    }
};
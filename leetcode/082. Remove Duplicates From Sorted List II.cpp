/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Remove Duplicates from Sorted List II
 Source:     https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Tags:       {Linked List}

 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
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
        if (!head || !head->next) return head;        
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy; 
        while (head->next && head->next->next) {
            if (head->next->val == head->next->next->val) {
                int val = head->next->val;
                while (head->next && head->next->val == val) {
                    ListNode* node = head->next;
                    head->next = head->next->next;
                    delete node;
                }            
            } else {
                head = head->next;
            }
        }
        return dummy.next;
    }
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) {
            return NULL;
        }
        if (!head->next || head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while (head && head->val == val) {
            ListNode *temp = head;
            head = head->next;
            delete temp;
        }        
        return deleteDuplicates(head);
    }
};
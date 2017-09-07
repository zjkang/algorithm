/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Palindrome Linked List
 Source:     https://leetcode.com/problems/palindrome-linked-list/
 Difficulty: Easy
 Tags:       {Linked List}, {Two Pointers}
 Company:    Amazon, Facebook

 Note:
 Given a singly linked list, determine if it is a palindrome.

 Follow up:
 Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* &left, ListNode* right) {
    	if (!right) return true;
    	if (!isPalindrome(left, right->next)) return false;
    	if (left->val != right->val) return false;
    	left = left->next;
    	return true;
    } 

    bool isPalindrome(ListNode* head) {
        ListNode* left = head, *right = head;
        return isPalindrome(left, right);
    }
};
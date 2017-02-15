/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Linked List Cycle
 Source:     https://leetcode.com/problems/linked-list-cycle/
 Tags:       {Linked List}, {Two Pointers} 
 Company:    Amazon, Microsoft, Bloomberg, Yahoo

 Notes:
 Given a linked list, determine if it has a cycle in it.
 Follow up:
 Can you solve it without using extra space?

 Solution: two pointers.
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
	bool hasCycle(ListNode *head) {
		if (!head || !head->next) return false;
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (true) {
			if (fast == slow) return true;
			if (!fast || !fast->next) return false;
			fast = fast->next->next;
			slow = slow->next;
		}
	}
};

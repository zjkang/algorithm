/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Linked List Cycle II
 Source:     http://oj.leetcode.com/problems/linked-list-cycle-ii/
 Tags:       {Linked List}, {Two Pointers}

 Notes:
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 Follow up:
 Can you solve it without using extra space?
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
	ListNode *detectCycle(ListNode *head) {
		if (!head || !head->next) return NULL;
		// {1,2}, tail connects to node {1}, if fast = head->next(不能使用)
		ListNode *slow = head;
		ListNode *fast = head; 
		while (fast && fast->next) { // assume cycle exists
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) break;
		}
		if (slow != fast) {
			return NULL; // no cycle
		}
		fast = head;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}    
		return slow;
	}
};

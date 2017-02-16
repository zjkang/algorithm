/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Reorder List
 Source:     https://leetcode.com/problems/reorder-list/
 Difficulty: Medium
 Tags:       {Linked List}

 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 You must do this in-place without altering the nodes' values.
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.
 Solution: Reverse the back half first, then reorder.
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
	ListNode* getMiddle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head->next;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode* reverse(ListNode* head) {
		ListNode dummy(0);
		dummy.next = head;
		while (head->next) {
			ListNode* mov = head->next;
			head->next = mov->next;
			mov->next = dummy.next;
			dummy.next = mov;
		}
		return dummy.next;
	}

	void reorderList(ListNode *head) {
		if (!head || !head->next) return;
		// move the middle of the list
		ListNode* mid = getMiddle(head);
		// reverse the second half lists
		ListNode* right = mid->next;
		mid->next = NULL;
		right = reverse(right);
		// merge from the list
		ListNode* left = head;
		while (left && right) {  
			ListNode* node1 = left->next;
			ListNode* node2 = right->next;
			left->next = right;
			right->next = node1;
			left = node1;
			right = node2;
		}
	}
};

/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Reverse Linked List I
 Source:     https://leetcode.com/problems/reverse-linked-list/
 Tags:       {Linked List}
 Company:    Uber, Facebook, Twitter, Zenefits, Amazon, Microsoft, Snapchat, Apple,
             Yahoo, Bloomberg, Yelp, Adobe

 Notes:
 Given a linear time non-recursive function that reverses a singly linked 
 list. The function should use no more than constant storage beyond that needed for 
 the list itself.
 Solution: 
 1. Recursive implementation uses O(n) storage on the function call stack.
 2. Iterative with two pointers and update the trailing pointer's next field. 
 	Use O(1) additional storage, and has O(n) 
*/

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int v) : val(v), next(NULL) {}
};

// Recursion
ListNode* reverse_linked_list(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* new_head = reverse_linked_list(head->next);
	head->next->next = head;
	head->next = NULL;
	return new_head;
}

// Iteration
ListNode* reverse_linked_list(ListNode* head) {
	if (!head) return NULL;
	ListNode* newhead = head;
	while (head->next) {
		ListNode* n = head->next;
		head->next = n->next;
		n->next = newhead;
		newhead = n;
	}
	return newhead;
}


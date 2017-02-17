/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Sort List (Merge Sort)
 Source:     https://leetcode.com/problems/sort-list/
 Tags:       {Linked List}, {Sort}
 
 Notes:
 Sort a linked list in O(nlogn) time using constant space complexity.
 Solution: merge sort.
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
	int getLength(ListNode *head) {
		int length = 0;
		while (head) {
			length++;
			head = head->next;
		}
		return length;
	}

	ListNode* mergeList(ListNode *head1, ListNode *head2) {
		ListNode dummy(0); 
		ListNode *cur = &dummy;
		while (head1 && head2) {
			ListNode **min = head1->val < head2->val ? &head1 : &head2;
			cur->next = *min;
			cur = cur->next;
			*min = (*min)->next;
		}
		if (!head1) cur->next = head2;
		if (!head2) cur->next = head1;
		return dummy.next;
	}

	ListNode* sortLinkedList(ListNode* &head, int N) {
		if (N == 0) return NULL;
		if (N == 1) {
			ListNode* cur = head;
			head = head->next; // update head pointer
			cur->next = NULL; // end of list
			return cur;
		}
		int half = N / 2;
		ListNode* head1 = sortLinkedList(head, half);
		ListNode* head2 = sortLinkedList(head, N - half);
		return mergeList(head1, head2);
	}

	ListNode *sortList(ListNode *head) {
		return sortLinkedList(head, getLength(head));
	}
};

/*
 Author:     Zhengjian kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Insertion Sort List
 Source:     https://leetcode.com/problems/insertion-sort-list/
 Tags:       {Linked List}, {Sort}

 Notes:
 Sort a linked list using insertion sort.
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
	ListNode *insertionSortList(ListNode *head) {
		if(!head) return NULL;
		ListNode dummy(0); // 1->2->5->null insert 3;     
		while (head) { // head: insert linked list node
			ListNode* node = &dummy;
			while (node->next != NULL && node->next->val <= head->val) {
				node = node->next;
			}          
			ListNode* temp = head->next;
			head->next = node->next;
			node->next = head;
			head = temp;
		}
		return dummy.next;
	}
};

class Solution {
public:
    // set a tail pointer and deal in two cases: the back of list/not
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return NULL;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* tail = &dummy;
        while (head) {
            ListNode* node = &dummy;
            while (node->next != head && node->next->val <= head->val) {
                node = node->next;
            }
            if (node->next == head) {
                tail = head;
                head = head->next;
            } else {
                tail->next = head->next;
                head->next = node->next;
                node->next = head;
                head = tail->next;
            }
        }
        return dummy.next;  
    }
};

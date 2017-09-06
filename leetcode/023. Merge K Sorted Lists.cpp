/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Merge k Sorted Lists
 Source:     https://leetcode.com/problems/merge-k-sorted-lists/
 Tags:       {Divide and Conquer}, {Linked List}, {Heap}
 Company:    LinkedIn, Google, Uber, Airbnb, Facebook, Twitter, Amazon, Microsoft
 
 Notes:
 Merge k sorted linked lists and return it as one sorted list. 
 Analyze and describe its complexity.
 Solution: Find the smallest list-head first using minimum-heap(lgk). 
 complexity: O(nlogk)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
  
class compare {
public:
    bool operator() (ListNode* left, ListNode* right) { // min-heap
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return NULL;        
        priority_queue<ListNode*, vector<ListNode*>, compare> heap;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!heap.empty()) {
            tail->next = heap.top(); 
            heap.pop();
            tail = tail->next;
            if(tail->next) {
                heap.push(tail->next);
            }
        }
        return dummy.next;
    }
};

/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Copy List with Random Pointer
 Source:     https://leetcode.com/problems/copy-list-with-random-pointer/
 Tags:       {Hash Table}, {Linked List}
 Company:    Amazon, Microsoft, Bloomberg, Uber

 Notes:
 A linked list is given such that each node contains an additional random pointer 
 which could point to any node in the list or null.
 Return a deep copy of the list.
 Solution: 1) uses constant extra space; 2) hashmap
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		// concatenate into one list
		for (auto cur = head; cur != NULL; cur = cur->next->next) { 
			RandomListNode *newNode = new RandomListNode(cur->label);
			newNode->next = cur->next;
			cur->next = newNode;
		}
		// assign random pointers
		for (auto cur = head; cur; cur = cur->next->next) { 
			if (cur->random) {
				cur->next->random = cur->random->next;                
			}
		}
		// detach list
		RandomListNode dummy(0);
		RandomListNode *curNew = &dummy; 
		for (auto cur = head; cur; cur = cur->next) {
			curNew->next = cur->next;
			curNew = curNew->next;
			cur->next = cur->next->next;
		}
		return dummy.next;
	}
};

class Solution {
public:  
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head) return NULL;
		unordered_map<RandomListNode*, RandomListNode*> map;
		RandomListNode dummy1(0);
		dummy1.next = head;
		RandomListNode dummy2(0);
		RandomListNode* pre = &dummy2;
		// copy linkedlist without random pointer
		while (head) {
			RandomListNode* newNode = new RandomListNode(head->label);
			map[head] = newNode;
			pre->next = newNode;
			pre = pre->next;
			head = head->next;
		}
		// copy random pointer
		head = dummy1.next;
		while (head) {
			if (head->random) {
				map[head]->random = map[head->random];
			}
			head = head->next;
		}
		return dummy2.next;
	}
};

class Solution {
typedef RandomListNode Node;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {        
        Node *cur = head;
        while(cur){
            Node *newnode = new Node(cur->label);
            newnode->next = cur->next;
            cur->next = newnode;
            cur = cur->next->next;
        }
        cur = head;
        while(cur){
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node dummy(0);
        Node *newcur = &dummy;
        cur = head;
        while(cur){
            newcur->next = cur->next;
            cur->next = cur->next->next;
            newcur = newcur->next;
            cur = cur->next;
        } 
        return dummy.next;
    }
};
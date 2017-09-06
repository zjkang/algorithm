/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Reverse Nodes in K-Group
 Source:     https://leetcode.com/problems/reverse-nodes-in-k-group/
 Tags:       {Linked List}
 Company:    Microsoft, Facebook
 
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.
 
 For example,
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5
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
            head = head->next;
            length++;
        }
        return length;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k <= 1) return head;
        int reverseTimes = getLength(head) / k;
        ListNode dummy(0); 
        dummy.next = head;
        head = &dummy;
        ListNode *cur = head->next;        
        while (reverseTimes--) {
            for (int i = 0; i < k - 1; ++i) {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = head->next;
                head->next = move;
            }
            head = cur;
            cur = head->next;
        }
        return dummy.next;
    }
};

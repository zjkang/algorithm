/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Odd Even Linked List
 Source:     https://leetcode.com/problems/odd-even-linked-list/
 Difficulty: Medium
 Tags:       {Linked List}
 
 Notes:
 Given a singly linked list, group all odd nodes together followed by the even nodes. 
 Please note here we are talking about the node number and not the value in the nodes.

 You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

 Example:
 Given 1->2->3->4->5->NULL,
 return 1->3->5->2->4->NULL.

 Note:
 The relative order inside both the even and odd groups should remain as it was in the input. 
 The first node is considered odd, the second node even and so on ...
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddDummy(0);
        ListNode evenDummy(0);
        ListNode* odd = &oddDummy;
        ListNode* even = &evenDummy;
        int num = 1;
        while (head) {
            if (num++ % 2 == 1) {
                odd->next = head;
                odd = odd->next;
            } else {
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        odd->next = evenDummy.next;
        even->next = NULL;
        return oddDummy.next;
    }
};
/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Intersection of Two Linked Lists
 Source:     https://leetcode.com/problems/intersection-of-two-linked-lists/
 Difficulty: Easy
 Tags:       {Linked List}
 Company:    Amazon, Microsoft, Bloomberg, Airbnb

 Note:
 Write a program to find the node at which the intersection of two singly linked lists begins.
 For example, the following two linked lists:
 A:          a1 → a2
                    ↘
                      c1 → c2 → c3
                    ↗            
 B:     b1 → b2 → b3
 begin to intersect at node c1.

 Notes:
 If the two linked lists have no intersection at all, return null.
 The linked lists must retain their original structure after the function returns.
 You may assume there are no cycles anywhere in the entire linked structure.
 Your code should preferably run in O(n) time and use only O(1) memory.
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        if (!p1 || !p2) return NULL;
        while (p1 && p2 && p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
            if (p1 == p2) return p1;
            if (!p1) p1 = headB;
            if (!p2) p2 = headA;
        }
        return p1;
    }
};

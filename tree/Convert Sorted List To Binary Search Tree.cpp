/*
 Author:     Zhengjian Kang
 Problem:    Convert Sorted List to Binary Search Tree
 Source:     https://oj.leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

    TreeNode *sortedListToBSTHelper(ListNode* &head, int length) {
        if (length == 0) return NULL;
        TreeNode* left = sortedListToBSTHelper(head, length / 2);
        TreeNode* root = new TreeNode(head->val);
        head = head->next; // move head pointer!
        TreeNode* right = sortedListToBSTHelper(head, length - length / 2 - 1);
        root->left = left;
        root->right = right;    
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBSTHelper(head, getLength(head));
    }
};

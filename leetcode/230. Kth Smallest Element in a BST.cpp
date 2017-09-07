/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Kth Smallest Element in a BST
 Source:     https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 Difficulty: Medium
 Tags:       {Binary Search}, {Tree}
 Company:    {Bloomberg}, {Uber}, {Google}
 
 Notes:
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

 Note: 
 You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 
 Follow up:
 What if the BST is modified (insert/delete operations) often and 
 you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int n = 0;
        TreeNode* res = kthSmallestHelper(root, k, n);
        return res->val;
    }
    
    TreeNode* kthSmallestHelper(TreeNode* root, int k, int& n) {
        if (!root) return NULL;
        TreeNode* left = kthSmallestHelper(root->left, k, n);
        if (left) return left;
        n += 1;
        if (k == n) return root;
        return kthSmallestHelper(root->right, k, n);
    }
};
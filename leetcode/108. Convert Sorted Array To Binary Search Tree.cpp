/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Convert Sorted Array to Binary Search Tree
 Source:     https://oj.leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 Difficulty: Easy
 Tags:       {Tree}, {Depth-first Search}
 Company:    {Airbnb}
 
 Notes:
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
    
    TreeNode *buildBST(vector<int> &num, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, start, mid - 1);
        root->right = buildBST(num, mid + 1, end);
        return root;
    }
};
/*
 Author:     Zhengjian Kang 
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Depth of Binary Tree
 Source:     https://oj.leetcode.com/problems/maximum-depth-of-binary-tree/
 Difficulty: Easy
 Tags:       {Tree}, {Depth-first Search}
 Company:    {Linkedin}, {Uber}, {Apple}, {Yahoo}
 
 Notes:
 Given a binary tree, find its maximum depth.
 The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
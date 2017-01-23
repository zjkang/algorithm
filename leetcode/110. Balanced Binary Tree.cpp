/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Balanced Binary Tree
 Source:     https://oj.leetcode.com/problems/balanced-binary-tree/
 Tags:       {Tree}
 
 Notes:
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as a binary tree in which 
 the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        int height = 0;
        return isBalancedHelper(root, height);
    }
    
    bool isBalancedHelper(TreeNode *root, int &height){
        if (!root) return true;    
        int leftHeight = 0, rightHeight = 0;
        if (!isBalancedHelper(root->left, leftHeight)) return false;
        if (!isBalancedHelper(root->right, rightHeight)) return false;
        if (abs(leftHeight - rightHeight) > 1) return false;
        height = 1 + max(leftHeight, rightHeight);
        return true;
    }
};

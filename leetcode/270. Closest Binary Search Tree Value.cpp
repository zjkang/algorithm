/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Closest Binary Search Tree Value
 Source:     https://leetcode.com/problems/closest-binary-search-tree-value/?tab=Description
 Difficulty: Easy
 Tags:       {Tree}, {Binary Search} 
 Company:    Microsoft, Google, Snapchat
 
 Notes:
 Given a non-empty binary search tree and a target value, 
 find the value in the BST that is closest to the target.

 Note:
 Given target value is a floating point.
 You are guaranteed to have only one unique value in the BST that is closest to the target.
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
    int closestValue(TreeNode* root, double target) {
        int closest = INT_MAX;
        double val;
        while (root) {
            if (closest == INT_MAX || val > abs(root->val - target)) {
                closest = root->val;
                val = abs(root->val - target);
            }
            if (root->val > target) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return closest;
    }
};
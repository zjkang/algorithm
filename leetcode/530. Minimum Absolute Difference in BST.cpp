/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Minimum Absolute Difference in BST
 Source:     https://leetcode.com/problems/minimum-absolute-difference-in-bst/#/description
 Difficulty: Easy
 Company:    Google
 Tags:       {Binary Search Tree}

 Notes:
 Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

 Example:
 Input:
   1
    \
     3
    /
   2
 Output:
 1

 Explanation:
 The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 Note: There are at least two nodes in this BST.
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
    void inorder(TreeNode* root, TreeNode* &prev, int& res) {
        if (!root) return;
        inorder(root->left, prev, res);
        if (prev) {
            res = min(res, abs(root->val - prev->val));
        }
        prev = root;
        inorder(root->right, prev, res);
    }

    int getMinimumDifference(TreeNode* root) {
        int res = INT_MAX;
        TreeNode* prev = NULL;
        inorder(root, prev, res);
        return res;
    }
};
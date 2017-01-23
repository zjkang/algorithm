/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Sum of Left Leaves
 Source:     https://leetcode.com/problems/sum-of-left-leaves/
 Tags:       {Tree}
 
 Notes:
 Find the sum of all left leaves in a given binary tree.
 Example:
    3
   / \
  9  20
    /  \
   15   7
 There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    void sumOfLeftLeavesHelper(TreeNode* root, bool isLeft, int& sum) {
        if (!root) return;
        if (!root->left && !root->right && isLeft) {
            sum += root->val;
        }
        sumOfLeftLeavesHelper(root->left, true, sum);
        sumOfLeftLeavesHelper(root->right, false, sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfLeftLeavesHelper(root, false, sum);
        return sum;
    }
};


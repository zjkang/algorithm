/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Path Sum II
 Source:     https://oj.leetcode.com/problems/path-sum-ii/
 Tags:       {Tree}
 
 Notes:
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 return
 [
   [5,4,11,2],
   [5,8,4,5]
 ]
 
 Solution: recursion; pre-order; dfs. 
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        vector<int> path;
        pathSumHelper(root, sum, path, res);
        return res;
    }

    void pathSumHelper(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &res) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (sum == root->val) {
                path.push_back(root->val); //
                res.push_back(path);
                path.pop_back(); // Recover to previous state
            }
            return;
        }        
        path.push_back(root->val);
        pathSumHelper(root->left, sum - root->val, path, res);
        pathSumHelper(root->right, sum - root->val, path, res);
        path.pop_back();
    }
};

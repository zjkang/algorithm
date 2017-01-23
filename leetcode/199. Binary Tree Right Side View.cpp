/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Right Side View 
 Source:     https://leetcode.com/problems/binary-tree-right-side-view/
 Tags:       {Tree}

 Notes:
 Given a binary tree, imagine yourself standing on the right side of it, 
 return the values of the nodes you can see ordered from top to bottom.
 For example:
 Given the following binary tree,
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
 You should return [1, 3, 4].
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
    void dfs(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (res.size() == level) {
            res.push_back(root->val);
        } else {
            res[level] = root->val;
        }
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};
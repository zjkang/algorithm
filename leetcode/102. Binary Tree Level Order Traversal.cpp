/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Level Order Traversal
 Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal/
 Difficulty: Medium
 Tags:       {Tree}, {Breadth-first Search}
 Company:    {Linkedin}, {Facebook}, {Amazon}, {Microsoft}, {Apple}, {Bloomberg}
 
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as:
 [
  [3],
  [9,20],
  [15,7]
 ]
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
    // Version 1: BFS
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); 
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};

// 8ms
class Solution {
public:
    // Version 2: dfs(recursion)
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        levelOrderHelper(root, 0, result);
        return result;
    }

    void levelOrderHelper(TreeNode *node, int level, vector<vector<int>> &result) {
        if (!node) return;
        if (result.size() <= level) { // initialize level
            result.push_back(vector<int>()); 
        }
        result[level].push_back(node->val);
        levelOrderHelper(node->left, level + 1, result);
        levelOrderHelper(node->right, level + 1, result);
    }
};
    

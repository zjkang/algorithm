/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Zigzag Level Order Traversal
 Source:     https://oj.leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 Tags:       {Tree}

 Notes:
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left 
 to right, then right to left for the next level and alternate between).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
      / \
     15  7
 return its zigzag level order traversal as:
 [
  [3],
  [20,9],
  [15,7]
 ]

 Solution: Queue + reverse. Straightforward method
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        bool left2right = false;
        while (!q.empty()) {
            left2right = !left2right;
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            if (!left2right) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
        }    
        return res;
    }
};

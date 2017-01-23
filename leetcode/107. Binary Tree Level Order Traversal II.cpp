/*
 Author:     Zhengjian Kang 
 Problem:    Binary Tree Level Order Traversal II
 Source:     https://oj.leetcode.com/problems/binary-tree-level-order-traversal-ii/
 Tags:       {Tree}
 
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
  [15,7]
  [9,20],
  [3],
 ]
 
 Solution: Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
        // reverse (one more function!)
        reverse(res.begin(), res.end());
        return res;
    }
};

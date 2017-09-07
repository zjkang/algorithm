/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Minimum Depth of Binary Tree
 Source:     https://oj.leetcode.com/problems/minimum-depth-of-binary-tree/
 Difficulty: Easy
 Tags:       {Tree}, {Depth-first Search}, {Breadth-first Search}

 Notes:
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node 
 down to the nearest leaf node.
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
// 16ms
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;                    
        if (!root->left && !root->right) return 1;            
        if (!root->left) return 1 + minDepth(root->right);   
        if (!root->right) return 1 + minDepth(root->left);            
        // root->left && root->right
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// 21ms
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            depth++;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (!node->left && !node->right) {
                    return depth; // min depth;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
};
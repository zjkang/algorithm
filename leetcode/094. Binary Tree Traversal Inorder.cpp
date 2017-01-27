/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Inorder Traversal
 Source:     http://oj.leetcode.com/problems/binary-tree-inorder-traversal/
 Difficulty: Medium
 Tags:       {Tree}, {Hash Table}, {Stack}
 Company:    {Microsoft}

 Notes:
 Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,3,2].
 Note: Recursive solution is trivial, could you do it iteratively?
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
    // Version 1: recursion
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        inorderTraversalHelper(root, res);
        return res;
    }

    void inorderTraversalHelper(TreeNode *node, vector<int> &res) {
        if (!node) return;
        inorderTraversalHelper(node->left, res);
        res.push_back(node->val);
        inorderTraversalHelper(node->right, res);
    }
};

class Solution {
public:
    // Version 2: iterative + stack
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk; // stack
        TreeNode *cur = root; // current pointer
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else if (!stk.empty()) {
                TreeNode* node = stk.top();
                stk.pop();
                res.push_back(node->val);
                cur = node->right; // move to right node!
            }
        }
        return res;
    }
};
    
class Solution {
public:
    // Morris Traversal
    // http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                // find predecessor
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;                    
                }
                    
                if (prev->right == cur) { // 2.b)
                    res.push_back(cur->val);
                    cur = cur->right;
                    prev->right = NULL;
                } else {// prev->right == NULL   // 2.a)
                    prev->right = cur;
                    cur = cur->left;
                }
            } else { // cur->left == NULL   // 1.
                res.push_back(cur->val);
                cur = cur->right;
            }
        }       
        return res;
    }
};

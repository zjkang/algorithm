/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Preorder Traversal
 Source:     http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 Difficulty: Medium
 Tags:       {Tree}, {Stack}
 
 Notes:
 Given a binary tree, return the preorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].
 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Recursive solution.      Time: O(n), Space: O(n).
           2. Iterative way (stack).   Time: O(n), Space: O(n).
           3. 更简单的使用 http://answer.ninechapter.com/solutions/binary-tree-preorder-traversal/
           4. Threaded tree (Morris).  Time: O(n), Space: O(1). // 面试应该不会用到
           http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        preorderTraversalHelper(root, res);
        return res;
    }

    void preorderTraversalHelper(TreeNode *node, vector<int> &res) {
        if (!node) return;
        res.push_back(node->val);
        preorderTraversalHelper(node->left, res);
        preorderTraversalHelper(node->right, res);
    }
};

class Solution {
public:
    // Version 2: iterative + stack
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk; // stack
        TreeNode *cur = root; // cur pointer
        while (cur || !stk.empty()) {
            if (cur) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            } else if (!stk.empty()) {
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
};
   
class Solution {
public: 
    // Version 3: 更简单的递归做法
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> path;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            root = s.top();
            s.pop();
            if (root == NULL) {
                continue;
            } else {
                path.push_back(root->val);
                s.push(root->right);
                s.push(root->left);
            }
        }
        return path;
    }
};

class Solution {
public:
    // Version 4: Morris (Thread) tree
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur) { // find predecessor 
                    prev = prev->right;
                }
                    
                if (prev->right == cur) { // 2.b
                    cur = cur->right;
                    prev->right = NULL;
                } else { // prev->right = NULL 2.a
                    res.push_back(cur->val); // only difference with inorder traversal
                    prev->right = cur;
                    cur = cur->left;
                }
            } else { // 1.
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

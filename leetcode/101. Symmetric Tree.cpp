/*
 Author:     Zhengjian Kang
 Problem:    Symmetric Tree
 Source:     https://oj.leetcode.com/problems/symmetric-tree/

 Tags:       {Tree}
 
 Notes:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 For example, this binary tree is symmetric:
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2 || t1->val != t2->val) return false;
        return isSymmetricHelper(t1->left, t2->right) &&
               isSymmetricHelper(t1->right, t2->left);
    }
};

class Solution {
public:
    // Version 2: BFS
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode *t1 = q.front(); q.pop();
            TreeNode *t2 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 || !t2 || t1->val != t2->val) return false;                
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};

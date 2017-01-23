/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Flatten Binary Tree to Linked List
 Source:     https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 Tags:       {Tree}
 
 Notes:
 Given a binary tree, flatten it to a linked list in-place.

 For example,
 Given
     1
    / \
   2   5
  / \   \
 3   4   6

 The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    void flattenHelper(TreeNode *root, TreeNode* &end) {
        if (!root) return;

        TreeNode *lend = NULL;
        TreeNode *rend = NULL;
        flattenHelper(root->left, lend);
        flattenHelper(root->right, rend);
        if (root->left) {
            lend->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        end = rend ? rend : (lend ? lend : root);
    }

    // keep lend and rend;
    void flatten(TreeNode *root) {
        TreeNode *end = NULL; // last node in linked list
        flattenHelper(root, end);
    }
};

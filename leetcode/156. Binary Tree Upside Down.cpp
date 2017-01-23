/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Upside Down
 Source:     https://leetcode.com/problems/binary-tree-upside-down/
 Tags:       {Tree}

 Notes:
 Given a binary tree where all the right nodes are either leaf nodes with a sibling 
 (a left node that shares the same parent node) or empty, 
 flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. 
 Return the new root.

 For example:
 Given a binary tree {1,2,3,4,5},
    1
   / \
  2   3
 / \
4   5
 return the root of the binary tree [4,5,2,#,#,3,1].
   4
  / \
 5   2
    / \
   3   1  
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
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        if(!root || (!root->left && !root->right)) 
            return root;
        TreeNode * parent = upsideDownBinaryTree(root->left);
        root->left->left = root->right;//because parameter could be NULL, so parent->left does not make sense.
        root->left->right = root; 
        root->left = NULL;
        root->right = NULL;
        return parent;
    }
};
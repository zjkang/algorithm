/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Validate Binary Search Tree
 Source:     http://oj.leetcode.com/problems/validate-binary-search-tree/
 Tags:       {Tree}

 Notes:
 Given a binary tree, 
 determine if it is a valid binary search tree (BST).
 
 Assume a BST is defined as follows:
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.
 Definition: 
 all elements in its left subtree are less-or-equal to the node (<=), 
 and all the elements in its right subtree are greater than the node (>). 
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
    // Pre-order traversal (lower bound + higher bound)
    bool isValidBST(TreeNode *root) {
        TreeNode *min = NULL, *max = NULL;
        return isValidBSTHelper(root, min, max);
    }

    bool isValidBSTHelper(TreeNode *node, TreeNode* min, TreeNode* max) {
        if (!node) return true;
        if ((min && node->val <= min->val) || (max && node->val >= max->val)) return false;
        return isValidBSTHelper(node->left, min, node) && 
               isValidBSTHelper(node->right, node, max);
    }
};

class Solution {
public:  
    // Inorder traversal & lower bound
    bool isValidBST(TreeNode *root) {
        TreeNode* min = NULL;
        return isValidBSTHelper(root, min);
    }

    bool isValidBSTHelper(TreeNode *node, TreeNode* &min) {
        if (!node) return true;
        if (node->left && !isValidBSTHelper(node->left, min)) return false;            
        if (min && node->val <= min->val) return false;            
        min = node;
        if (node->right && !isValidBSTHelper(node->right, min)) return false;            
        return true;
    }
};

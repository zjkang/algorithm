/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Lowest Common Ancestor of a Binary Tree
 Source:     https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
 Difficulty: Medium
 Tags:       {Tree}
 Company:    {Amazon}, {Linkedin}, {Apple}, {Facebook}, {Microsoft}
 
 Notes:
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 According to the definition of LCA on Wikipedia: 
 “The lowest common ancestor is defined between two nodes v and w as the lowest node in T 
 that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
 For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
 Another example is LCA of nodes 5 and 4 is 5, 
 since a node can be a descendant of itself according to the LCA definition.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestorHelper(root->left, p, q);
        TreeNode* right = lowestCommonAncestorHelper(root->right, p, q);
        if (left && right) {
            return root;
        }
        return left ? left : right ? right : NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;
        return lowestCommonAncestorHelper(root, p, q);
    }
};

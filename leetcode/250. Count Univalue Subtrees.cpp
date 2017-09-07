/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Count Univalue Subtrees
 Source:     https://leetcode.com/problems/count-univalue-subtrees/
 Difficulty: Medium
 Tags:       {Tree}
 
 Notes:
 Given a binary tree, count the number of uni-value subtrees.
 A Uni-value subtree means all nodes of the subtree have the same value.

 For example:
 Given binary tree,
          5
         / \
        1   5
       / \   \
      5   5   5
 return 4.
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
    bool countUnivalSubtreesHelper(TreeNode* root, int& val) {
        if (!root) {
            return true;
        }
        if (!root->left && !root->right) {
            val++;
            return true;
        }
        bool leftUnival = countUnivalSubtreesHelper(root->left, val);
        bool rightUnival = countUnivalSubtreesHelper(root->right, val);
        if (leftUnival && rightUnival) {
            if ((root->left && root->val != root->left->val) ||
                (root->right && root->val != root->right->val)) {
                return false;        
            }
            val++;
            return true;
        }
        return false;
    }

    int countUnivalSubtrees(TreeNode* root) {
        int val = 0;
        countUnivalSubtreesHelper(root, val);
        return val;
    }
};

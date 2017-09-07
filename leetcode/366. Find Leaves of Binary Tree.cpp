/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Leaves of Binary Tree
 Source:     https://leetcode.com/problems/find-leaves-of-binary-tree/
 Difficulty: Medium
 Tags:       {Tree}
 Company:    {Linkedin}
 
 Notes:
 Given a binary tree, collect a tree's nodes as if you were doing this: 
 Collect and remove all leaves, repeat until the tree is empty.

 Example:
 Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
 Returns [4, 5, 3], [2], [1].

 Explanation:
 1. Removing the leaves [4, 5, 3] would result in this tree:
           1
          / 
         2          
 2. Now removing the leaf [2] would result in this tree:
           1          
 3. Now removing the leaf [1] would result in the empty tree:
           []         
 Returns [4, 5, 3], [2], [1].
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
    int findLeavesHelper(TreeNode* root, vector<vector<int>>& result) {
        if (!root) {
            return -1;
        }
        int leftLevel = findLeavesHelper(root->left, result);
        int rightLevel = findLeavesHelper(root->right, result);
        int level = max(leftLevel, rightLevel) + 1;
        
        if (result.size() == level) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        return level;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> result;
        findLeavesHelper(root, result);
        return result;
    }
};
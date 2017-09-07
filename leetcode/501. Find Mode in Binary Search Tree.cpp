/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Mode in Binary Search Tree
 Source:     https://leetcode.com/problems/find-mode-in-binary-search-tree/
 Difficulty: Easy
 Tags:       {Tree}
 Company:    {Google}

 Notes:
 Given a binary search tree (BST) with duplicates, 
 find all the mode(s) (the most frequently occurred element) in the given BST.

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than or equal to the node's key.
 The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
 Both the left and right subtrees must also be binary search trees.
 For example:
 Given BST [1,null,2,2],
   1
    \
     2
    /
   2
 return [2].

 Note: If a tree has more than one mode, you can return them in any order.

 Follow up: Could you do that without using any extra space? 
 (Assume that the implicit stack space incurred due to recursion does not count).
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
    void dfs(TreeNode* root, unordered_map<int,int>& map, int& maxVal) {
        if (!root) {
            return;
        }
        int key = root->val;
        map[key]++;
        maxVal = max(maxVal, map[key]);
        
        dfs(root->left, map, maxVal);
        dfs(root->right, map, maxVal);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int maxVal = 0;
        unordered_map<int,int> map;
        
        dfs(root, map, maxVal);
        for (auto e : map) {
            if (e.second == maxVal) {
                res.push_back(e.first);
            }
        }
        return res;
    }
};
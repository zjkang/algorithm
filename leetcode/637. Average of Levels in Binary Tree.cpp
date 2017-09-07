/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Average of Levels in Binary Tree
 Source:     https://leetcode.com/problems/average-of-levels-in-binary-tree/#/description
 Difficulty: Easy
 Company:    Facebook
 Tags:       {Tree}

 Notes:
 Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

 Example 1:
 Input:
     3
    / \
   9  20
     /  \
    15   7
 Output: [3, 14.5, 11]
 Explanation:
 The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
 Note:
 The range of node's value is in the range of 32-bit signed integer.
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
    void dfs(TreeNode* root, int depth, vector<pair<long long, int>>& val) {
        if (!root) return;
        if (val.size() == depth) {
            val.push_back({root->val, 1});
        } else {
            val[depth].first += root->val;
            val[depth].second++;
        }
        
        dfs(root->left, depth+1, val);
        dfs(root->right, depth+1, val);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<long long, int>> val;
        dfs(root, 0, val);
        vector<double> res;
        for (auto i : val) {
            res.push_back(((double)i.first) / i.second);
        }
        return res;
    }
};
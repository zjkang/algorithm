/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Largest Value in Each Tree Row
 Source:     https://leetcode.com/problems/find-largest-value-in-each-tree-row/#/description
 Difficulty: Medium
 Company:    Linkedin
 Tags:       {Tree, Depth-first Search, Breadth-first Search}

 Notes:
 You need to find the largest value in each row of a binary tree.

 Example:
 Input: 
 
           1
          / \
         3   2
        / \   \  
       5   3   9 
 
 Output: [1, 3, 9]
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
    void dfs(TreeNode* root, int level, vector<int>& res) {
        if (!root) return;
        if (res.size() == level) {
            res.push_back(root->val);
        } else {
            res[level] = max(res[level], root->val);
        }
        dfs(root->left, level+1, res);
        dfs(root->right, level+1, res);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }
};

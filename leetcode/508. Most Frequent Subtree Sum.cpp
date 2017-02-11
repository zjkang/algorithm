/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Most Frequent Subtree Sum
 Source:     https://leetcode.com/problems/most-frequent-subtree-sum/
 Difficulty: Medium
 Company:    Google
 Tags:       {Tree}, {Hash Table}

 Notes:
 Given the root of a tree, you are asked to find the most frequent subtree sum. 
 The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node 
 (including the node itself). So what is the most frequent subtree sum value? If there is a tie, 
 return all the values with the highest frequency in any order.

 Examples 1
 Input:

   5
  /  \
 2   -3
 return [2, -3, 4], since all the values happen only once, return all of them in any order.
 Examples 2
 Input:

   5
  /  \
 2   -5
 return [2], since 2 happens twice, however -5 only occur once.
 Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
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
    int dfs(TreeNode* root, unordered_map<int,int>& map) {
        if (!root) {
            return 0;
        }
        int leftSum = dfs(root->left, map);
        int rightSum = dfs(root->right, map);
        int sum = leftSum + rightSum + root->val;
        map[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> map;
        dfs(root, map);
        vector<int> res;
        int max = 0;
        for(auto e : map) {
            if (e.second > max) {
                res.clear();
                res.push_back(e.first);
                max = e.second;
            } else if (e.second == max) {
                res.push_back(e.first);
            }
        }
        return res;
    }
};
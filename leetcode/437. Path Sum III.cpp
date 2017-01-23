/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Path Sum III
 Source:     https://leetcode.com/problems/path-sum-iii/
 Tags:       {Tree}
 
 Notes:
 You are given a binary tree in which each node contains an integer value. 
 Find the number of paths that sum to a given value.
 The path does not need to start or end at the root or a leaf, 
 but it must go downwards (traveling only from parent nodes to child nodes).
 The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

 Example:
 root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
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
    void pathSum(TreeNode* root, int sum, int& result) {
        if (!root) {
            return;
        }
        if (root->val == sum) {
            result++;
        }
        pathSum(root->left, sum - root->val, result);
        pathSum(root->right, sum - root->val, result);
    }

    void traverse(TreeNode* root, int sum, int& result) {
        if (!root) {
            return;
        }
        pathSum(root, sum, result);
        traverse(root->left, sum, result);
        traverse(root->right, sum, result);
    }
    
    int pathSum(TreeNode* root, int sum) {
        int result = 0;
        traverse(root, sum, result);
        return result;
    }
};


/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Longest Consecutive Sequence II
 Source:     https://leetcode.com/problems/binary-tree-longest-consecutive-sequence-ii/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Tree}

 Notes:
 Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree.
 
 Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
 
 Example 1:
 Input:
         1
        / \
       2   3
 Output: 2
 Explanation: The longest consecutive path is [1, 2] or [2, 1].
 Example 2:
 Input:
         2
        / \
       1   3
 Output: 3
 Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
 Note: All the values of tree nodes are in the range of [-1e7, 1e7].
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
    void dfs(TreeNode* root, int& res, vector<int>& local) {
        if (!root) return;
        // max length of increasing order starting from root
        // max length of decreasing order starting from root
        vector<int> leftRes(2, 1), rightRes(2, 1);
        dfs(root->left, res, leftRes);
        dfs(root->right, res, rightRes);
        
        int leftInc = leftRes[0], leftDec = leftRes[1];
        int rightInc = rightRes[0], rightDec = rightRes[1];
        
        if (root->left && abs(root->left->val - root->val) == 1) {
            if (root->val > root->left->val) {
                local[0] = leftInc + 1;
            } else {
                local[1] = leftDec + 1;
            }
        }
        if (root->right && abs(root->right->val - root->val) == 1) {
            if (root->val > root->right->val) {
                local[0] = max(rightInc + 1, local[0]);
            } else {
                local[1] = max(rightDec + 1, local[1]);
            }
        }
        
        res = max({local[0], local[1], res});
        if (local[0] > 1 && local[1] > 1) {
            res = max(res, local[0] + local[1] - 1);
        }
    }

    int longestConsecutive(TreeNode* root) {
        int res = 0;
        vector<int> local(2, 1);
        dfs(root, res, local);
        return res;
    }
};

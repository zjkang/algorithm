/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Sum Root to Leaf Numbers
 Source:     https://oj.leetcode.com/problems/sum-root-to-leaf-numbers/
 Difficulty: Medium
 Tags:       {Tree}, {Depth-first Search}

 Notes:
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 Find the total sum of all root-to-leaf numbers.
 For example,
   1
  / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 Return the sum = 12 + 13 = 25.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val; *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
        int sum = 0;
        sumNumbersHelper(root, 0, sum);
        return sum;
    }
    
    void sumNumbersHelper(TreeNode *node, int num, int &sum) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { 
            sum += num;
            return;
        }
        sumNumbersHelper(node->left, num, sum);
        sumNumbersHelper(node->right, num, sum);
    }
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;        
        int res = 0;
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *node = q.front().first;
            int sum = q.front().second * 10 + node->val;
            q.pop();
            if (!node->left && !node->right) {
                res += sum;
                continue;
            }         
            if (node->left) q.push(make_pair(node->left, sum));                
            if (node->right) q.push(make_pair(node->right, sum));
        }
        return res;
    }
};

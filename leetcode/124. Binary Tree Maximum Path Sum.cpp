/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Maximum Path Sum
 Source:     https://oj.leetcode.com/problems/binary-tree-maximum-path-sum/
 Difficulty: Hard
 Tags:       {Tree}, {Depth-first Search}
 Company:    {Microsoft}, {Baidu}

 Notes:
 Given a binary tree, find the maximum path sum.
 The path may start and end at any node in the tree.
 For example:
 Given the below binary tree,
   1
  / \
 2   3
 Return 6.

 Solution: divide and conquer (recursion).
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // return max singlePath ending with node
    int maxPathSumHelper(TreeNode *node, int &maxPath) {
        if (!node) return 0;
        int l = maxPathSumHelper(node->left, maxPath);
        int r = maxPathSumHelper(node->right, maxPath);
        int singlePath = max({node->val, max(l, r) + node->val}); // max (root as node)
        maxPath = max({maxPath, singlePath, l + r + node->val});
        return singlePath;
    }

    int maxPathSum(TreeNode *root) {
        int maxPath = INT_MIN;
        maxPathSumHelper(root, maxPath);
        return maxPath;
    }
};

/*
 扩展题目: 树中最大路径和
 链接: http://www.itint5.com/oj/#13
 问题: 
 给定一棵树的根结点，树中每个结点都包含一个整数值val。
 我们知道树中任意2个结点之间都存在唯一的一条路径，路径值为路径上所有结点值之和。
 请计算最大的路径值（允许路径为空）。
 样例：
    -10
  /  |  \
 2   3   4
    / \
   5  -1
      /
     6
    /
   -1
 最大的路径值为13，相应的路径为5到6之间的路径。
 扩展：此题算法也可用来解决另一个非常常见的面试题“树的直径”（求树中任意两结点路径的长度的最大值）。
 可以认为树中每个结点的val值为1，那么求最长路径相当于求路径值最大的路径。

 Solution: LeetCode中Binary Tree Maximum Path Sum的扩展，这里是树，而非二叉树。
*/

/*
树结点的定义(请不要在代码中定义该类型)
struct TreeNode {
    int val;
    vector<TreeNode*> children;  //该结点的儿子结点
 };
*/
#include <climits>

int maxTreePathSumHelper(TreeNode *root, int &res) {
    if (!root) {
        return res;
    }
    
    int N = root->children.size();
    int first = 0, second = 0; // 容许路径为空
    for (int i = 0; i < N; ++i) {
        int sum = maxTreePathSumHelper(root->children[i], res);
        if (sum > first) {
            second = first;
            first = sum;
        } else if (sum > second) {
            second = sum;
        }
    }
    
    int maximum = root->val;
    maximum = max(maximum, root->val + first);
    res = max({res, maximum, root->val + first + second});
    return maximum;
}

int maxTreePathSum(TreeNode *root) {
    int res = 0;
    maxTreePathSumHelper(root, res);
    return res;
}

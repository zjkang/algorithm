/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Unique Binary Search Trees II
 Source:     http://oj.leetcode.com/problems/unique-binary-search-trees-ii/
 Tags:       {Tree}

 Notes:
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: DFS directly
*/

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }

    vector<TreeNode*> generateTreesHelper(int start, int end) { // 1...n, left = 1, right = n
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);
            return res;
        }
        for (int k = start; k <= end; k++) { // root starts from k; 拆分成不同left, right subtree
            auto leftTrees = generateTreesHelper(start, k - 1);
            auto rightTrees = generateTreesHelper(k + 1, end);
            for (int i = 0; i < leftTrees.size(); i++) {
                for (int j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i]; // concatenate into left or right
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    // Version 2: DFS + DP
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode*> dp[n + 1];
        dp[0] = vector<TreeNode *>(1, (TreeNode *)NULL);
        for (int i = 1; i <= n; ++i) { // level i = 1...n
            for (int j = 1; j <= i; ++j) { // root->value = 1 to i
                for (int m = 0; m < dp[j - 1].size(); ++m) { // left subtree structure
                    for (int k = 0; k < dp[i - j].size(); ++k) { // right subtree structure
                        TreeNode *root = new TreeNode(j);
                        CopyTree(dp[j - 1][m], root->left, 0);
                        CopyTree(dp[i - j][k], root->right, j);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    // DFS: Binary Search Tree Structure Copy
    void CopyTree(TreeNode *original, TreeNode* &newNode, int diff) {
        if (!original) return;
        newNode = new TreeNode(original->val + diff);
        CopyTree(original->left, newNode->left, diff);
        CopyTree(original->right, newNode->right, diff);
    }
};

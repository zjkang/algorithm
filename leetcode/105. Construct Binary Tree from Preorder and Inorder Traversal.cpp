/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Construct Binary Tree from Preorder and Inorder Traversal
 Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 Tags:       {Tree}

 Notes:
 Given preorder and inorder traversal of a tree, construct the binary tree.
 Note:
 You may assume that duplicates do not exist in the tree.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTreeHelper(vector<int>::iterator preorder, vector<int>::iterator inorder, int length) {
        if (length <= 0) return NULL;
        auto it = find(inorder, inorder + length, *preorder);
        int ll = it - inorder, rl = length - ll - 1;
        TreeNode *root = new TreeNode(*preorder);
        root->left = buildTreeHelper(preorder + 1, inorder, ll);
        root->right = buildTreeHelper(preorder + 1 + ll, inorder + ll + 1, rl);
        return root;
    }
};


class Solution {
public:
    typedef vector<int>::iterator ITERATOR;
    TreeNode* buildTreeHelper(ITERATOR preorder, ITERATOR inorder, int length, unordered_map<int, ITERATOR>& map) {
        if (length <= 0) return NULL;
        auto it = map[*preorder];
        int ll = it - inorder, rl = length - ll - 1;
        TreeNode* root = new TreeNode(*preorder);
        root->left = buildTreeHelper(preorder+1, inorder, ll, map);
        root->right = buildTreeHelper(preorder+1+ll, inorder+ll+1, rl, map);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        unordered_map<int, ITERATOR> map;
        for (auto it = inorder.begin(); it != inorder.end(); ++it) {
            map[*it] = it;
        }
        return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size(), map);
    }
};




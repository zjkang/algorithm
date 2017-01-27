/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Construct Binary Tree from Inorder and Postorder Traversal
 Source:     https://oj.leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 Difficulty: Medium
 Tags:       {Tree}, {Array}, {Depth-first Search}
 Company:    {Microsoft}

 Notes:
 Given inorder and postorder traversal of a tree, construct the binary tree.
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

// 69ms
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTreeHelper(inorder.begin(), postorder.begin(), inorder.size());
    }

    TreeNode *buildTreeHelper(vector<int>::iterator inorder, vector<int>::iterator postorder, int length) {
        if (length <= 0) return NULL;
        auto it = find(inorder, inorder + length, *(postorder + length - 1));
        int left_len = it - inorder;
        TreeNode *root = new TreeNode(*(postorder + length - 1));
        root->left = buildTreeHelper(inorder, postorder, left_len);
        root->right = buildTreeHelper(inorder + left_len + 1, postorder + left_len, length - left_len - 1);
        return root;
    }
};

// 25 ms using hashmap
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> idx;
        for(int i=0; i<inorder.size(); i++){
            idx[inorder[i]] = i;
        }
        return build(inorder, postorder, 0, 0, inorder.size(), idx);
    }
    
    TreeNode *build(vector<int> &inorder, vector<int> &postorder, int ii, int pi, int N, unordered_map<int, int> &idx){
        if(N == 0) return NULL;
        int r = postorder[pi+N-1], lN = idx[r] - ii, rN = N-lN-1;
        TreeNode *root = new TreeNode(r);
        root->left = build(inorder, postorder, ii, pi, lN, idx);
        root->right = build(inorder, postorder, ii+lN+1, pi+lN, rN, idx);
        return root;
    }
};

/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Search Tree Iterator
 Source:     https://leetcode.com/problems/binary-search-tree-iterator/
 Difficulty: Medium
 Tags:       {Tree}, {Stack}, {Design}
 Company:    {Linkedin}, {Google}, {Facebook}, {Microsoft}

 Notes:
 Implement an iterator over a binary search tree (BST). 
 Your iterator will be initialized with the root node of a BST.
 Calling next() will return the next smallest number in the BST.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 where h is the height of the tree.
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !s.empty();    
    }

    /** @return the next smallest number */
    int next() {
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else if (!s.empty()) {
                TreeNode* n = s.top(); 
                s.pop();
                cur = n->right;
                return n->val;
            }
        }
    }
    
private:
    TreeNode* cur;
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

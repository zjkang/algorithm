/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Recover Binary Search Tree
 Source:     http://oj.leetcode.com/problems/recover-binary-search-tree/
 Difficulty: Hard
 Tags:       {Tree}, {Depth-first Search}

 Notes:
 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
           2. recursive solution. O(n) space. with only auxiliary two pointers.
           3. Morris inorder traversal. O(1) space. with only auxiliary two pointers.
*/

/*
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
    // Inorder traversal, space O(n)
    void inorderTraversal(TreeNode *root, vector<TreeNode*> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root);
        inorderTraversal(root->right, inorder);
    }

    // 1, 2, 3, 4, 5 -> 1, 3, 2, 4, 5
    // 1, 2, 3, 4, 5 -> 1, 4, 3, 2, 5
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> inorder;
        inorderTraversal(root, inorder);
        TreeNode *first = NULL, *second = NULL;
        for (int i = 1; i < inorder.size(); ++i) {
            if (inorder[i - 1]->val < inorder[i]->val) {
                continue;                
            }
            if (!first) first = inorder[i - 1];
            second = inorder[i]; // second must be fixed when first = NULL
        }
        swap(first->val, second->val); // swap values
    }
};

class Solution {
public:
    // Inorder traversal with 2 pointers
    void recoverTree(TreeNode *root) {
        TreeNode* prev = NULL, *first = NULL, *second = NULL;
        recoverTreeHelper(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeHelper(TreeNode* root, TreeNode* &prev, TreeNode* &first, TreeNode* &second) {
        if (root == NULL) return;
        // if (first && second) return; // BUG! find 2 pointers.
        recoverTreeHelper(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (first == NULL) first = prev;                
            second = root; // 两种情况, 相邻或者不相邻的两个点置换, 无论哪一种, 这个都可以cover.
        }
        prev = root;
        recoverTreeHelper(root->right, prev, first, second);
    }
};

class Solution {
public:
    // Morris tree, inorder traversal
    void recoverTree(TreeNode *root) {
        TreeNode *cur = root, *prev = NULL;
        TreeNode *first = NULL, *second = NULL, *last = NULL;
        while (cur) {
            if (cur->left == NULL) {
                compare(last, cur, first, second);
                last = cur;
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;                    
                }

                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    compare(last, cur, first, second);
                    last = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }

    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second) {
        if (last && last->val > cur->val) {
            if (!first) first = last;
            second = cur;
        }
    }
};

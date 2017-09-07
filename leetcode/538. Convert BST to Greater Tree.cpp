/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Convert BST to Greater Tree
 Source:     https://leetcode.com/problems/convert-bst-to-greater-tree/#/description
 Difficulty: Medium
 Company:    Amazon
 Tags:       {Tree}

 Notes:
 Given a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

 Example:

 Input: The root of a Binary Search Tree like this:
              5
            /   \
           2     13
 
 Output: The root of a Greater Tree like this:
             18
            /   \
          20     13
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
    void convertBSTHelper(TreeNode* root, int& sum) {
        if (!root) return;
        convertBSTHelper(root->right, sum);
        root->val += sum;
        sum = root->val;
        convertBSTHelper(root->left, sum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertBSTHelper(root, sum);
        return root;
    }
};
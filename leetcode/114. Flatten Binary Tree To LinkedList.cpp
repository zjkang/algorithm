/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Flatten Binary Tree to Linked List
 Source:     https://oj.leetcode.com/problems/flatten-binary-tree-to-linked-list/
 Difficulty: Medium
 Tags:       {Tree}, {Depth-first Search}
 Company:    Microsoft

 Notes:
 Given a binary tree, flatten it to a linked list in-place.
 For example,
 Given
     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 Hints:
 If you notice carefully in the flattened tree, each node's right child points to the next node 
 of a pre-order traversal.

 Solution: divide and conquer(Recursion) Return the last element of the flattened sub-tree.
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
	void flattenHelper(TreeNode *root, TreeNode* &end) {
		if (!root) return;
		TreeNode *lend = NULL;
		TreeNode *rend = NULL;
		flattenHelper(root->left, lend);
		flattenHelper(root->right, rend);
		if (root->left) {
			lend->right = root->right;
			root->right = root->left;
			root->left = NULL;
		}
		end = rend ? rend : (lend ? lend : root);
	}

	void flatten(TreeNode *root) {
		TreeNode *end = NULL; // last node in linked list
		flattenHelper(root, end);
	}
};

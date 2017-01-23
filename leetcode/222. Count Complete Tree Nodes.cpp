/*
 Author:     Zhengjian Kang
 Problem:    Count Complete Tree Nodes
 Source:     https://leetcode.com/problems/count-complete-tree-nodes/
 Tags:       {Tree}
 
 Notes:
 Given a complete binary tree, count the number of nodes.

 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, 
 except possibly the last, is completely filled, 
 and all nodes in the last level are as far left as possible. 
 It can have between 1 and 2h nodes inclusive at the last level h.
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
    int treeHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int leftHeight  = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);
        int totalNodes  = 0;
        
        if (leftHeight == rightHeight) {
            totalNodes  = 1 + ((1 << leftHeight) - 1);
            totalNodes += countNodes(root->right);
        }
        else {
            totalNodes = 1 + ((1 << rightHeight) - 1);
            totalNodes += countNodes(root->left);
        }
        return totalNodes;
    }
};

/*
 Author:     Zhengjian Kang
 Problem:    Binary Tree Paths
 Source:     https://leetcode.com/problems/binary-tree-paths/
 Tags:       {Tree}
 
 Notes:
 Given a binary tree, return all root-to-leaf paths.
 For example, given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:
["1->2->5", "1->3"]
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
    void makeString(vector<int>& onePath, vector<string>& results) {
        string res;
        for (int i = 0; i < onePath.size(); ++i) {
            if (i != 0) res += "->";
            res += to_string(onePath[i]);
        }
        results.push_back(res);
    }

    void binaryTreePaths(TreeNode* root, vector<int>& onePath, vector<string>& results) {
        if (!root) return;
        if (!root->left && !root->right) {
            onePath.push_back(root->val);
            makeString(onePath, results);
            onePath.pop_back();
            return;
        }
        onePath.push_back(root->val);
        binaryTreePaths(root->left, onePath, results);
        binaryTreePaths(root->right, onePath, results);
        onePath.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        vector<int> onePath;
        binaryTreePaths(root, onePath, results);
        return results;
    }
};
/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Construct Binary Tree from String
 Source:     https://leetcode.com/problems/construct-binary-tree-from-string/#/description
 Difficulty: Medium
 Company:    Amazon
 Tags:       {Tree, String}

 Notes:
 You need to construct a binary tree from a string consisting of parenthesis and integers.

 The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure.

 You always start to construct the left child node of the parent first if it exists.

 Example:
 Input: "4(2(3)(1))(6(5))"
 Output: return the tree root node representing the following tree:

        4
      /   \
     2     6
    / \   / 
   3   1 5   
 Note:
 There will only be '(', ')', '-' and '0' ~ '9' in the input string.
 An empty tree is represented by "" instead of "()".
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
    int getNumber(const string& s, int& index) {
        int pos = 1;
        if (s[index] == '-') {
            pos = -1;
            index++;
        }
        int num = 0;
        while (index < s.size() && isdigit(s[index])) {
            num = num * 10 + (s[index] - '0');
            index++;
        }
        return num * pos;
    }

    TreeNode* dfs(string s, int& index) {
        if (index == s.size()) return NULL;
        if (s[index] == '(' || s[index] == ')') return NULL;
        
        int num = getNumber(s, index);
        TreeNode* root = new TreeNode(num);
        
        if (index < s.size() && s[index] == '(') {
            root->left = dfs(s, ++index);
            index++;
        } else {
            root->left = NULL;
        }
        if (index < s.size() && s[index] == '(') {
            root->right = dfs(s, ++index);
            index++;
        } else {
            root->right = NULL;
        }
        
        return root;
    }
        
    TreeNode* str2tree(string s) {
        TreeNode* root = NULL;
        if (s.empty() || s.size() == 0) return NULL;
        int index = 0;
        return dfs(s, index);
    }
};

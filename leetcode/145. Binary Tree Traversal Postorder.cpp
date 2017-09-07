/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Binary Tree Postorder Traversal 
 Source:     http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 Difficulty: Hard
 Tags:       {Tree}, {Stack}
 
 Notes:
 Given a binary tree, return the postorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].
 Note: Recursive solution is trivial, could you do it iteratively?
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
    void postorderTraversalHelper(TreeNode *node, vector<int> &res) {
        if (!node) return;
        postorderTraversalHelper(node->left, res);
        postorderTraversalHelper(node->right, res);
        res.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        postorderTraversalHelper(root, res);
        return res;
    }
};

// root - > root->right - > root->left
// similar to preorder, then reverse
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            if (cur != NULL) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->right;
            } else {
                cur = st.top()->left;
                st.pop();
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode *last = NULL;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            } else {
                TreeNode *peak = stk.top();
                if (peak->right && last != peak->right) { // last: visited tag
                    cur = peak->right;
                } else {
                    res.push_back(peak->val); 
                    stk.pop();
                    last = peak;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    //Morris (thread) tree
    //http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode dump(0);
        dump.left = root;
        TreeNode *cur = &dump, *prev = NULL;
        while (cur) {
            if (cur->left == NULL) { // 1.
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;                    
                }

                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else { // reverse print path
                    printReverse(cur->left, prev, res);  // call print
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    // print the reversed tree nodes 'from' -> 'to'.
    void printReverse(TreeNode* from, TreeNode *to, vector<int>& res) {
        reverse(from, to);
        
        TreeNode *p = to;
        while (true) {
            res.push_back(p->val);
            if (p == from) {
                break;                
            }
            p = p->right;
        }
        reverse(to, from);
    }
    
    // reverse the tree nodes 'from' -> 'to'.
    void reverse(TreeNode *from, TreeNode *to) {
        if (from == to) return;            
        TreeNode *x = from, *y = from->right, *z;
        while (true) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == to) {
                break;                
            }
        }
    }
};

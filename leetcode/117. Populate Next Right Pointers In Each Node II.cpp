/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Populating Next Right Pointers in Each Node II
 Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 Tags:       {Tree}

 Notes:
 Follow up for problem "Populating Next Right Pointers in Each Node".
 What if the given tree could be any binary tree? Would your previous solution still work?
 Note:
 You may only use constant extra space.
 For example,
 Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
 After calling your function, the tree should look like:
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL

 Solution: 1. iterative way with constant extra space.
           2. BFS
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // Iteration: level by level
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *cur = root;
        while (cur) { // level starting point
            TreeLinkNode* level = cur;
            TreeLinkNode* last = NULL;
            cur = NULL;
            while (level) { // level trarverse
                TreeLinkNode *left = level->left;
                TreeLinkNode* right = level->right;
                if (!cur && (left || right)) {
                    cur = left ? left : right;
                }
                if (left) {
                    if (last) last->next = left;
                    last = left;
                }
                if (right) {
                    if (last) last->next = right;
                    last = right;
                }
                level = level->next;
            }
        }
    }
};

class Solution {
public:    
    // Iterative BFS + Queue
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode *last = NULL;
        while (!q.empty()) {
            int size = q.size();
            last = NULL;
            for (int i = 0; i < size; ++i) {
                TreeLinkNode* node = q.front(); q.pop();
                if (last) last->next = node;
                last = node;
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }
    }
};

// recursion
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode *p = root->next;
        while(p){
            if(p->left){
                p = p->left;
                break;
            }
            if(p->right){
                p = p->right;
                break;
            }
            p = p->next;
        }
        if(root->right)
            root->right->next = p;
        if(root->left)
            root->left->next = root->right ? root->right : p;
        connect(root->right);
        connect(root->left);
    }
};



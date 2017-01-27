/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Populating Next Right Pointers in Each Node I
 Source:     https://oj.leetcode.com/problems/populating-next-right-pointers-in-each-node/
 Difficulty: Medium
 Tags:       {Tree}, {Depth-first Search}
 Company:    {Microsoft}

 Notes:
 Given a binary tree
 struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 Initially, all next pointers are set to NULL.
 Note:
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
      1
    /  \
   2    3
  / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
      1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \  / \
 4->5->6->7 -> NULL
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
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *level = root;
            TreeLinkNode *last = NULL;          
            while (level && level->left) {
                if (last) {
                    last->next = level->left;                    
                }
                level->left->next = level->right;
                last = level->right;
                level = level->next;
            }
            root = root->left;
        }
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        if(root->left)
            root->left->next = root->right;
        if(root->right && root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeLinkNode* p = Q.front();
            Q.pop();
            if(p->left){
                p->left->next = p->right;
                Q.push(p->left);
            }
            if(p->right){
                if(p->next)
                    p->right->next = p->next->left;
                Q.push(p->right);
            }
        }
    }
};

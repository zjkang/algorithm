/*
 Author:     Zhengjian Kang
 Problem:    K-Balanced Tree
 Source:     EPI 6.2, pg. 230
 
 Notes:
 Define a node in a binary tree to be k-balanced if the difference in the number of 
 nodes in its left and right subtrees is no more than k. 
 Design an algorithm that takes as input a binary tree and positive
 integer k, and returns a node u in the binary tree such that u is not k-balanced, but all
 of u's descendants are k-balanced. If no such node exists, return null. For example, 
 when applied to the binary tree in Figure 6.1 on Page 55, your algorithm should 
 return Node J if k = 3. 
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

pair<TreeNode*, int> find_non_k_balanced_node_helper(TreeNode* root, int k) {
    // Empty tree
    if (!root) { 
        return {NULL, 0};
    }
    // Early return if left subtree is not k-balanced
    auto L = find_non_k_balanced_node_helper(root->left, k);
    if (L.first) {
        return L;
    }
    // Early return if right subtree is not k-balanced
    auto R = find_non_k_balanced_node_helper(root->right, k);
    if (R.first) {
        return R;
    }
    int node_num = L.second + R.second + 1; // #nodes in n
    if (abs(L.second - R .second) > k) {
        return {root, node_num};
    }
    return {NULL, node_num};
}

TreeNode* find_non_k_balanced_node(TreeNode* root, int k) {
    return find_non_k_balanced_node_helper(root, k).first;
}

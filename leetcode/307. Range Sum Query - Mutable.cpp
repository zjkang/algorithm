/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Range Sum Query - Mutable
 Source:     https://leetcode.com/problems/range-sum-query-mutable/
 Difficulty: Medium
 Tags:       {Segment Tree}, {Binary Indexed Tree}
 
 Notes:
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

 The update(i, val) function modifies nums by updating the element at index i to val.
 Example:
 Given nums = [1, 3, 5]

 sumRange(0, 2) -> 9
 update(1, 2)
 sumRange(0, 2) -> 8
 Note:
 The array is only modifiable by the update function.
 You may assume the number of calls to update and sumRange function is distributed evenly.
*/

struct SegmentTreeNode {
    int start;
    int end;
    int val;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e, int v) : start(s), end(e), val(v) {}
};

class SegmentTree {
public:
    SegmentTree(): root(NULL) {}
    
    void buildTree(vector<int>& nums) {
        root = buildTreeHelper(nums, 0, nums.size()-1);
    }
    
    void update(int i, int val) {
        updateTreeHelper(root, i, val);
    }
    
    int sumRange(int i, int j) {
        if (i > j || i > root->end || j < root->start) return 0;
        return sumRangeHelper(root, i, j);
    }

private:
    SegmentTreeNode* root;
    
    SegmentTreeNode* buildTreeHelper(vector<int>& nums, int start, int end) {
        if (start > end) return NULL; // illegal input
        if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        }
        
        int mid = start + (end - start) / 2;
        SegmentTreeNode* left  = buildTreeHelper(nums, start, mid);
        SegmentTreeNode* right = buildTreeHelper(nums, mid + 1, end);
        SegmentTreeNode* root  = new SegmentTreeNode(start, end, left->val + right->val);
        root->left  = left;
        root->right = right;
        
        return root;
    }

    void updateTreeHelper(SegmentTreeNode* root, int i, int val) {
        if (!root || i < root->start || i > root->end) {
            return;
        }
        if (i == root->start && i == root->end) {
            root->val = val;
            return;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (i <= mid) {
            updateTreeHelper(root->left, i, val);   
        } else {
            updateTreeHelper(root->right, i, val);
        }
        
        root->val = root->left->val + root->right->val;
    }   
    
    int sumRangeHelper(SegmentTreeNode* root, int start, int end) {
        if (!root || start > root->end || end < root->start) return 0;
        if (start == root->start && end == root->end) {
            return root->val;
        }
        
        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return sumRangeHelper(root->left, start, end);
        } else if (start > mid) {
            return sumRangeHelper(root->right, start, end);
        } else {
            return sumRangeHelper(root->left, start, mid) + 
                   sumRangeHelper(root->right, mid+1, end);
        }
        
    }
};


class NumArray {
public:
    NumArray(vector<int> &nums) : d_tree() {
        d_tree.buildTree(nums);
    }

    void update(int i, int val) {
        d_tree.update(i, val);
    }

    int sumRange(int i, int j) {
        return d_tree.sumRange(i, j);
    }
private: 
    SegmentTree d_tree;
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
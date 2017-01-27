/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Verify Preorder Sequence in Binary Search Tree
 Source:     https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/
 Difficulty: Medium
 Tags:       {Tree}, {Stack}
 Company:    Zenefits
 
 Notes:
 Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 You may assume each number in the sequence is unique.

 Follow up:
 Could you do it using only constant space complexity?
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        int index = -1;
        for (int i = 0; i < preorder.size(); ++i) {
            if (preorder[i] < low) {
                return false;
            }
            while (index >= 0 && preorder[i] > preorder[index]) {
                low = preorder[index--];
            }
            preorder[++index] = preorder[i];
        }
        return true;
    }
};

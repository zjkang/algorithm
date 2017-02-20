/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Kth Smallest Element in a Sorted Matrix
 Source:     https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/?tab=Description
 Difficulty: Medium
 Tags:       {Binary Search}, {Heap}
 Company:    Google, Twitter
 
 Notes:
 Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
 find the kth smallest element in the matrix.

 Note that it is the kth smallest element in the sorted order, not the kth distinct element.

 Example:
 matrix = [
    [ 1,  5,  9],
    [10, 11, 13],
    [12, 13, 15]
 ],
 k = 8,

 return 13.
 Note: 
 You may assume k is always valid, 1 ≤ k ≤ n2.
 */

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                q.push(matrix[i][j]);
                if (q.size() > k) q.pop();
            }
        }
        return q.top();        
    }
};
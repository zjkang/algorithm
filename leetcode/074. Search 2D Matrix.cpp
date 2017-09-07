/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Search a 2D Matrix
 Source:     https://leetcode.com/problems/search-a-2d-matrix/?tab=Description
 Tags:       {Array}, {Binary Search}

 Notes:
 Write an efficient algorithm that searches for a value in an m x n matrix. 
 This matrix has the following properties:
 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,
 Consider the following matrix:
 [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
 ]
 Given target = 3, return true.
 */

class Solution {
public:
    //Sort by row first and col next. 
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int M = matrix.size(), N = matrix[0].size();
        int start = 0, end = M - 1; // search by row
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        int row = end; // search by column
        if (row < 0) {
            return false;
        }
        start = 0, end = N - 1;
        while (start <= end) { // <=
            int mid = start + (end - start) / 2;
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] < target) {
                start = mid + 1; // mid + 1
            } else {
                end = mid - 1; // mid - 1
            }
        }
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int M = matrix.size(), N = matrix[0].size();
        int l = 0, h = M*N-1, m;
        while (l + 1 < h) {
            m = l + (h - l) / 2;
            int i = m / N, j=m % N;
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) l = m;
            else h = m;
        }
        return matrix[l/N][l%N] == target || matrix[h/N][h%N] == target ? true : false;
    }
};
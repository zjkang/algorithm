/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Range Sum Query 2D - Immutable
 Source:     https://leetcode.com/problems/range-sum-query-2d-immutable/
 Difficulty: Medium
 Tags:       {Dynamic Programming}
 
 Notes:
 This is the problem when I first phone interviewed at Google.

 Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner 
 (row1, col1) and lower right corner (row2, col2).

 Range Sum Query 2D
 The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), 
 which contains sum = 8.

 Example:
 Given matrix = [
   [3, 0, 1, 4, 2],
   [5, 6, 3, 2, 1],
   [1, 2, 0, 1, 5],
   [4, 1, 0, 1, 7],
   [1, 0, 3, 0, 5]
 ]

 sumRegion(2, 1, 4, 3) -> 8
 sumRegion(1, 1, 2, 2) -> 11
 sumRegion(1, 2, 2, 4) -> 12
 Note:
 You may assume that the matrix does not change.
 There are many calls to sumRegion function.
 You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) 
        : d_dp(matrix) {
        if (d_dp.empty() || d_dp[0].empty()) return;
        row = d_dp.size();
        col = d_dp[0].size();
        
        for (int i = 1; i < col; ++i) {
            d_dp[0][i] += d_dp[0][i-1];
        }
        
        for (int i = 1; i < row; ++i) {
            d_dp[i][0] += d_dp[i-1][0];
        }
        
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                d_dp[i][j] += d_dp[i-1][j] + d_dp[i][j-1] - d_dp[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (d_dp.empty() || d_dp[0].empty()) return 0;
        if (row1 == 0 && col1 == 0) return d_dp[row2][col2];
        else if (row1 == 0) return d_dp[row2][col2] - d_dp[row2][col1-1];
        else if (col1 == 0) return d_dp[row2][col2] - d_dp[row1-1][col2];
        else return d_dp[row2][col2] - d_dp[row1-1][col2] - d_dp[row2][col1-1] + d_dp[row1-1][col1-1];
    }
private:
    int row;
    int col;
    vector<vector<int>> d_dp;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Line of Consecutive One in Matrix
 Source:     https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Array}

 Notes:
 Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.

 Example:
 Input:
 [[0,1,1,0],
  [0,1,1,0],
  [0,0,0,1]]
 Output: 3
 Hint: The number of elements in the given matrix will not exceed 10,000.
*/

class Solution {
public:
    vector<int> dx = {0, 1, 1, 1};
    vector<int> dy = {1, -1, 0, 1};
    int dfs(vector<vector<int>>& M, int r, int c, vector<vector<vector<int>>>& dp, vector<vector<bool>>& visited) {
        if (M[r][c] == 0) return 0;
        if (visited[r][c]) {
            return *max_element(dp[r][c].begin(), dp[r][c].end());
        }
        int rows = M.size(), cols = M[0].size();
        visited[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            dp[r][c][i] = 1;
            int x = r + dx[i], y = c + dy[i];
            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                dfs(M, x, y, dp, visited);
                dp[r][c][i] += dp[x][y][i];
            }
        }
        return *max_element(dp[r][c].begin(), dp[r][c].end());
    }
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int rows = M.size(), cols = M[0].size();
        int res = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(4, 0)));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (M[i][j] == 1) {
                    res = max(dfs(M, i, j, dp, visited), res);
                }
            }
        }
        return res;
    }
};
/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Palindromic Subsequence
 Source:     https://leetcode.com/problems/longest-palindromic-subsequence/
 Difficulty: Medium
 Company:    Amazon, Uber
 Tags:       {Dynamic Programming}

 Notes:
 Given a string s, find the longest palindromic subsequence's length in s. 
 You may assume that the maximum length of s is 1000.

 Example 1:
 Input:

 "bbbab"
 Output:
 4
 One possible longest palindromic subsequence is "bbbb".
 Example 2:
 Input:

 "cbbd"
 Output:
 2
 One possible longest palindromic subsequence is "bb".
*/

class Solution {
public:
    // dp[i][j]: longest Palindromic length between i and j.
    // dp[i][j] = max(dp[i][j-1], s[k] == s[j] ? dp[k+1][j] + 2)
    int longestPalindromeSubseq(string s) {
        if (s.empty()) {
            return 0;
        }
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 1));
        for (int l = 1; l <= len; ++l) {
            for (int i = 0; i + l <= len; ++i) {
                if (l == 1) {
                    dp[i][i] = 1;
                } else if (l == 2) {
                    dp[i][i+1] = s[i] == s[i+1] ? 2 : 1;
                } else {
                    dp[i][i+l-1] = dp[i][i+l-2];
                    for (int j = i; j < i + l - 1; ++j) {
                        if (s[j] == s[i+l-1]) {
                            dp[i][i+l-1] = max(dp[i][i+l-1], j+1 <= i+l-2 ? dp[j+1][i+l-2] + 2 : 2);
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][len-1];
    }
};


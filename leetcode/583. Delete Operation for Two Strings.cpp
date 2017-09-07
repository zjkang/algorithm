/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Delete Operation for Two Strings
 Source:     https://leetcode.com/problems/delete-operation-for-two-strings/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {String}

 Notes:
 Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.

 Example 1:
 Input: "sea", "eat"
 Output: 2
 Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
 Note:
 The length of given words won't exceed 500.
 Characters in given words can only be lower-case letters.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Find max length of common sub sequence: dp problem
        int s1 = word1.size(), s2 = word2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
        for (int i = 0; i < s1; ++i) {
            for (int j = 0; j < s2; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                } else {
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return s1 + s2 - 2*dp[s1][s2];
    }
};

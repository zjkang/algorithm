/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Unique Binary Search Trees I
 Source:     http://oj.leetcode.com/problems/unique-binary-search-trees/
 Tags:       {Tree}, {DP}
 
 Notes:
 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 For example,
 Given n = 3, there are a total of 5 unique BST's.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3
 Solution:
 http://fisherlei.blogspot.com/2013/03/leetcode-unique-binary-search-trees.html
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) { // up to n
            for (int j = 1; j <= i; j++) { // value j as the root 
                dp[i] += dp[j - 1] * dp[i - j]; // left=j, right=i-j-1
            }
        }
        return dp[n];
    }
};

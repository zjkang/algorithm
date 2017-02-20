/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Arranging Coins
 Source:     https://leetcode.com/problems/arranging-coins/?tab=Description
 Difficulty: Easy
 Tags:       {Binary Search}, {Math}
 Company:    GoDaddy
 
 Notes:
 You have a total of n coins that you want to form in a staircase shape, 
 where every k-th row must have exactly k coins.

 Given n, find the total number of full staircase rows that can be formed.
 n is a non-negative integer and fits within the range of a 32-bit signed integer.

 Example 1:

 n = 5

 The coins can form the following rows:
 ¤
 ¤ ¤
 ¤ ¤

 Because the 3rd row is incomplete, we return 2.
 Example 2:

 n = 8

 The coins can form the following rows:
 ¤
 ¤ ¤
 ¤ ¤ ¤
 ¤ ¤

 Because the 4th row is incomplete, we return 3.
*/

class Solution {
public:
    int arrangeCoins(int n) {
        int start = 0, end = n;
        int res = 0;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            long long val = (1 + mid) * (long long)mid / 2;
            if (val > n) {
                end = mid;
            } else if (val == n) {
                return mid;
            } else {
                start = mid;
            }
        }
        if ((1 + end) * (long long)end / 2 <= n) {
            return end;
        }
        return start;
    }
};






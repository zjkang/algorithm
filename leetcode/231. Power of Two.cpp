/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Power of Two
 Source:     https://leetcode.com/problems/power-of-two/#/description
 Difficulty: Easy
 Tags:       {Math, Bit Manipulation}
 Company:    Google
 
 Notes:
 Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};

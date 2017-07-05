/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Sum of Square Numbers
 Source:     https://leetcode.com/problems/sum-of-square-numbers/#/description
 Difficulty: Easy
 Company:    Linkedin
 Tags:       {Math}

 Notes:
 Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.

 Example 1:
 Input: 5
 Output: True
 Explanation: 1 * 1 + 2 * 2 = 5
 Example 2:
 Input: 3
 Output: False
*/

class Solution {
public:
    bool isSquare(int c) {
        int val = (int)sqrt(c);
        return val * val == c ? true : false;
    }
    bool judgeSquareSum(int c) {
        if (isSquare(c)) return true;
        int end = (c + 1) / 2;
        for (int i = 1; i <= end && i <= c / i; ++i) {
            int r = c - i * i;
            if (isSquare(r)) return true;
        }
        return false;
    }
};

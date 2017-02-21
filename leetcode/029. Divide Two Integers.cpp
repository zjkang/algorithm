/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Divide Two Integers
 Source:     https://leetcode.com/problems/divide-two-integers/?tab=Description
 Difficulty: Medium
 Math:       {Binary Search}, {Math}

 Notes:
 Divide two integers without using multiplication, division and mod operator.
 Solution: Use << operator. (multiply operator)
*/

class Solution {
public:
    // corner case: overflow:
    //Input:  -2147483648, -1; Expected:   2147483647
    // Version 1: long long type
    int divide(int x, int y) {
        if (x == 0) return 0;
        assert(y != 0);
        if (x == INT_MIN && y == -1) return INT_MAX; // overflow        
        bool pos = (x > 0 && y > 0) || (x < 0 && y < 0);
        long long xx = abs((long long)x);
        long long yy = abs((long long)y);
        int res = 0;
        while (xx >= yy) {
            int power = 1;
            while ((yy << power) <= xx) { // overflow
                power++;
            }
            res += 1 << (power-1);
            xx -= yy << (power-1);
        }
        return pos ? res : -res;
    }
};


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) 
            throw invalid_argument("divisor cannot be zero!");
        //Corner cases
        if(dividend == INT_MIN && divisor==-1) return INT_MAX;
        if(dividend == INT_MIN && divisor== 1) return INT_MIN;
        if(dividend > 0) return -divide(-dividend, divisor);
        if(divisor > 0) return -divide(dividend, -divisor);
        if(dividend > divisor) return 0;
        if(divisor == -1) return -dividend;
        int helper = divisor, res = 1;
        while(helper >= dividend - helper){
            res <<= 1;
            helper <<= 1;
        }
        return res + divide(dividend - helper, divisor);
    }
};




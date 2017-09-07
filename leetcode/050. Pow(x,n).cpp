/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Pow(x, n)
 Source:     https://leetcode.com/problems/powx-n/?tab=Description
 Difficulty: Medium
 Tags:       {Binary Search}, {Math}
 Company:    Bloomberg, Google, Linkedin, Facebook

 Notes:
 Implement pow(x, n).
 Solution: 快速幂
 */
class Solution {
public:
    double epsilon = 1e-6;
    bool equals(double x, double y) {
        return abs(x - y) < epsilon; 
    }

    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (equals(x, 0.0) || equals(x, 1.0)) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        double half = pow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};
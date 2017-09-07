/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Sqrt(x)
 Source:     https://leetcode.com/problems/sqrtx/?tab=Description
 Tags:       {Binary Search}, {Math}
 Company:    Bloomberg, Apple, Facebook

 Notes:
 Implement int sqrt(int x).
 Compute and return the square root of x.
 */

class Solution {
public:
    int sqrt(int x) {
        assert(x >= 0);
        int l = 0, r = x / 2 + 1;
        while (l + 1 < r) {
            // long long mid = l + (r - l) / 2; // overflow problem. 
            // long long sq = mid * mid;
            // if (sq == x) {
            //     return mid;
            // } else if (sq < x) {
            //     l = mid;
            // } else {
            //     r = mid;
            // }

            int mid = l + (r - l) / 2;
            int quot = x / mid;
            if (quot == mid) {
                return quot;
            } else if (quot > mid) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (r * r == x) return r;
        return l;
    }
};

class Solution {
public:
    const double eps = 1.0e-12;
    // 0 means equal, -1 means smaller, +1 means larger
    int compare(double a, double b) {
        if (a == 0) a += eps;
        if (b == 0) b += eps;
        double diff = (a - b) / b;
        return diff > eps ? 1 : diff < -eps ? -1 : 0;
    };

    double square_root(double x) {
        // Decide the search range according to x
        double l, r;
        if (compare(x, 1.0) < 0) { // x < 1.0
            l = x; r = 1.0;
        } else { // x >= 1.0
            l = 1.0; r = x;
        }
        // Keep searching if l < r
        while (compare(l, r) < 0) {
            double m = l + 0.5 * (r - l);
            double square_m = m * m;
            if (compare(square_m, x) == 0) {
                return m;
            } else if (compare(square_m, x) < 0) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }
};

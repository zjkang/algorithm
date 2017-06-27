/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Minimum Factorization
 Source:     https://leetcode.com/problems/minimum-factorization/#/description
 Difficulty: Medium
 Company:    Tencent
 Tags:       {Recursion, Math}

 Notes:
 Given a positive integer a, find the smallest positive integer b whose multiplication of each digit equals to a.

 If there is no answer or the answer is not fit in 32-bit signed integer, then return 0.

 Example 1
 Input:
 48 
 Output:
 68

 Example 2
 Input:
 15
 Output:
 35
*/

class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) return 1;
        long long res = 0;
        vector<int> digits;
        for (int i = 9; i >= 2; --i) { // prefers to larger digit from 9 to 2...
            if (a % i == 0) {
                digits.push_back(i);
                a /= i;
                ++i;
            }
            if (a == 1) break;
        }
        if (a > 1) return 0;
        for (int i = digits.size()-1; i >= 0; --i) {
            res = res * 10 + digits[i];
        }
        if (res > INT_MAX) return 0;
        return (int)res;
    }
};
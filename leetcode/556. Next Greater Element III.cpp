/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Next Greater Element III
 Source:     https://leetcode.com/problems/next-greater-element-iii/#/description
 Difficulty: Medium
 Company:    Bloomberg
 Tags:       {String}

 Notes:
 Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

 Example 1:
 Input: 12
 Output: 21
 
 Example 2:
 Input: 21
 Output: -1
*/

class Solution {
public:
    // 75819 - 75891
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int i = s.size()-2;
        for (; i >= 0; --i) {
            if (s[i] < s[i+1])
                break;
        }
        if (i < 0) return -1;
        sort(s.begin()+i+1, s.end());
        for (int j = i+1; j < s.size(); ++j) { // binary search
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        }
        stringstream ss(s);
        long long res = 0; 
        ss >> res;
        return res > INT_MAX ? -1 : (int)res;
    }
};


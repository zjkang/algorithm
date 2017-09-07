/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Minimum in Rotated Sorted Array I
 Source:     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 Tags:       {Array}, {Binary Search}
 Company:    Microsoft

 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 You may assume no duplicate exists in the array.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (num[l] < num[r]) return num[l];
            else if (num[l] < num[m]) l = m;
            else r = m;
        }
        return min(num[l], num[r]);
    }   
};

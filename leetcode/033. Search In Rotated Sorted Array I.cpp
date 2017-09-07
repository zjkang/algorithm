/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Search in Rotated Sorted Array
 Source:     https://leetcode.com/problems/search-in-rotated-sorted-array/?tab=Description
 Tags:       {Binary Search}, {Array}
 Company:    Linkedin, Bloomberg, Uber, Facebook, Microsoft

 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (search-in-rotated-sorted-array.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2 3; 5 6 0 -1- [2 3 4]
 */

class Solution {
public:
    int search(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[start] < A[mid]) {
                if (A[start] <= target && target <= A[mid]) {
                    end = mid;
                } else {
                    start = mid;
                }
            } else {
                if (A[mid] <= target && target <= A[end]) {
                    start = mid;
                } else {
                    end = mid;
                }
            }
        }

        if (A[end] == target) {
            return end;
        } 
        if (A[start] == target) {
            return start;
        }
        return -1;
    }
};

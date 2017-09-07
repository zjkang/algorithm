/*
 Author:     Zhengjian kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Search Insert Position
 Source:     http://oj.leetcode.com/problems/search-insert-position/
 Difficulty: Easy
 Tags:       {Array}, {Binary Search}

 Notes:
 Given a sorted array and a target value, return the index if the target is found. If not, 
 return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.
 Here are few examples.
 [1,3,5,6], 5 -> 2
 [1,3,5,6], 2 -> 1
 [1,3,5,6], 7 -> 4
 [1,3,5,6], 0 -> 0
 */

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                return mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (A[end] == target) {
            return end;
        } else if (A[end] < target) {
            return end + 1;
        }
        if (A[start] == target) {
            return start;
        } else if (A[start] < target) {
            return start + 1;
        }
        return start; 
    }
};
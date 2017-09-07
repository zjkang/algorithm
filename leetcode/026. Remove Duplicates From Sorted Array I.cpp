/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu 
 Problem:    Remove Duplicates from Sorted Array I
 Source:     https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 Difficulty: Easy
 Tags:       {Array}, {Two Pointers}
 Company:    Microsoft, Bloomberg, Facebook

 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int start = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0 || A[i] != A[start - 1]) {
                A[start++] = A[i];        	            	
            }
        }
        return start;
    }
};

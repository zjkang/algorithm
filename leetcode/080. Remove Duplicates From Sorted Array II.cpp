/*
 Author:    Zhengjian Kang
 Email:     zhengjian.kang@nyu.edu
 Problem:   Remove Duplicates from Sorted Array II
 Source:    https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?tab=Description
 Difficulty: Medium
 Tags:      {Array}, {Two Pointers}
 Company:   Facebook

 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int start = 2; // start point is different with 025_removeDuplicateFromSortedArrayI
        for (int i = 2; i < n; ++i) {
            if (A[i] != A[start - 1] || A[i] != A[start - 2]) {
                A[start++] = A[i];        	            	
            }
        }
        return start;
    }
};

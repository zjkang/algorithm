/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Search in Rotated Sorted Array II
 Source:     https://leetcode.com/problems/search-in-rotated-sorted-array-ii/?tab=Description 
 Tags:       {Array}, {Binary Search}

 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: 1. Sequence search. O(n)
 Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
           2. Peudo-binary search O(n)
 */

class Solution {
public:
    // Version 1: O(n) corner case: 112111111111
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++) {
            if (A[i] == target) {
                return true;                
            }
        }
        return false;
    }

    // Version 2: binary search O(n)
    bool search(int A[], int n, int target) {
        if (n == 0) return false;
        return search(A, 0, n-1, target);
    }
    
    bool search(int A[], int start, int end, int target) {
        if (start > end) return false;
        int mid = start + (end - start) / 2;
        if (A[mid] == target) return true;
        
        if (A[start] < A[mid]) {
            if (target >= A[start] && target < A[mid]) {
                return search(A, start, mid - 1, target);                
            } else {
                return search(A, mid + 1, end, target);                
            }
        } else if (A[start] > A[mid]) {
            if (target > A[mid] && target <= A[end]) {
                return search(A, mid + 1, end, target);                
            } else {
                return search(A, start, mid - 1, target);                
            }
        } else {
            return search(A, start + 1, mid - 1, target) || search(A, mid + 1, end, target);            
        }
    }
};
/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Median of Two Sorted Arrays
 Source:     http://oj.leetcode.com/problems/median-of-two-sorted-arrays/
 Difficulty: Hard
 Tags:       {Binary Search}, {Array}, {Divide and Conquer}
 Company:    Google, Zenefits, Microsoft, Apple, Yahoo, Dropbox, Adobe

 Notes:
 There are two sorted arrays A and B of size m and n respectively. 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 Refer details for http://fisherlei.blogspot.com/2012/12/leetcode-median-of-two-sorted-arrays.html
 Solution: Time complexity: O(log(m+n))
*/

class Solution {
public:
    //O(log(m+n)), find the k-th sorted array elements
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total % 2) {
            return findKthSortedArrays(A, m, 0, B, n, 0, total / 2 + 1); // odd            
        } else {
            return (findKthSortedArrays(A, m, 0, B, n, 0, total / 2) + 
                    findKthSortedArrays(A, m, 0, B, n, 0, total / 2 + 1)) / 2; // even            
        }
    }

    double findKthSortedArrays(int A[], int m, int A_start, int B[], int n, int B_start, int k) {
        if (A_start >= m) return B[B_start + k - 1];
        if (B_start >= n) return A[A_start + k - 1];  
        if (k == 1) return min(A[A_start], B[B_start]);

        int A_key = A_start + k / 2 - 1 < m ? A[A_start + k / 2 - 1] : INT_MAX; // corner case (k/2-1)
        int B_key = B_start + k / 2 - 1 < n ? B[B_start + k / 2 - 1] : INT_MAX;
        if (A_key < B_key) {
            return findKthSortedArrays(A, m, A_start + k / 2, B, n, B_start, k - k / 2);
        } else {
            return findKthSortedArrays(A, m, A_start, B, n, B_start + k / 2, k - k / 2);
        }
    }
};

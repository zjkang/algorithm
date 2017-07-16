/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Subarray
 Source:     http://oj.leetcode.com/problems/maximum-subarray/
 Difficulty: Easy
 Topic:      {Array, Dynamic Programming, Divide and Conquer}
 Company:    Linkedin, Bloomberg, Microsoft
 Notes:
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 For example, given the array [-2,1,-3,4,-1,2,1,-5,4], the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */

class Solution {
public:
	// dp: max value ending with index i
    int maxSubArray(int A[], int n) {
        int res = A[0]; // max value
        int dp = A[0]; // max value ending at index i
        for (int i = 1; i < n; ++i) {
            dp = max(A[i], dp + A[i]); 
            res = max(dp, res);
        }
        return res;
    }
};


class Solution {
public:
    // sliding window
    int maxSubArray(int A[], int n) {
        int max = INT_MIN:
        int sum = 0; // starting point for max value
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            max = max(sum, max);
            sum = max(sum, 0);
        }
        return max;
    }
};

// divide and conquer
// http://www.geeksforgeeks.org/divide-and-conquer-maximum-sum-subarray/
class Solution {
public:
    int maxSubArray(int A[], int n) {    
        int maxV = INT_MIN;  
        return maxArray(A, 0, n-1, maxV);      
    }  

    int maxArray(int A[], int left, int right, int& maxV) {  
        if (left > right) return INT_MIN;  
        int mid = (left + right) / 2;  
        int lmax = maxArray(A, left, mid -1, maxV);  
        int rmax = maxArray(A, mid + 1, right, maxV);  
        int sum = 0, mlmax = 0;  
        for (int i = mid -1; i >= left; i--) {  
            sum += A[i];  
            if (sum > mlmax)  
                mlmax = sum;  
        }  
        sum = 0; int mrmax = 0;  
        for (int i = mid +1; i<=right; i++) {  
            sum += A[i];  
            if (sum > mrmax)  
                mrmax = sum;  
        }  
        int localMaxV = max({lmax, rmax, mlmax + mrmax + A[mid]});
        maxV = max(maxV, localMaxV);  
        return localMaxV;  
    }  
};

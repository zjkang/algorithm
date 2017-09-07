/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Product Subarray
 Source:     https://leetcode.com/problems/maximum-product-subarray/#/description
 Difficulty: Medium
 Topic:      {Array, Dynamic Programming}
 Company:    Linkedin

 Note: 
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution {
public:
    int maxProduct(int A[], int n) {
        int result = A[0];
        int maximum = A[0], minimum = A[0];
        int curMax = A[0], curMin = A[0];
        for (int i = 1; i < n; ++i) {
            curMax = max({A[i], A[i] * maximum, A[i] * minimum});
            curMin = min({A[i], A[i] * maximum, A[i] * minimum});
            maximum = curMax;
            minimum = curMin;
            result = max(result, maximum);
        }
        return result;
    }
};


class Solution {
public:
    int maxProduct(int A[], int n) {
        int res = A[0], minimum = A[0], maximum = A[0];
        for(int i=1; i<n; i++){
            if(A[i] < 0)
                swap(minimum, maximum);
            minimum = min(A[i], A[i]*minimum);
            maximum = max(A[i], A[i]*maximum);
            res = max(res, maximum);
        }
        return res;
    }
};

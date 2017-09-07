/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Product of Three Numbers
 Source:     https://leetcode.com/problems/maximum-product-of-three-numbers/#/description
 Difficulty: Easy
 Company:    Intuit
 Tags:       {Array, Math}

 Notes:
 Given an integer array, find three numbers whose product is maximum and output the maximum product.
 
 Example 1:
 Input: [1,2,3]
 Output: 6
 Example 2:
 Input: [1,2,3,4]
 Output: 24
 Note:
 The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
 Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        
        int res = nums[sz-1] * nums[sz-2] * nums[sz-3];
        res = max(res, nums[0] * nums[1] * nums[sz-1]);
        return res;
    }
};

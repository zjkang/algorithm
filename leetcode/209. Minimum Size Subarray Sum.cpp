/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Minimum Size Subarray Sum
 Source:     https://leetcode.com/problems/minimum-size-subarray-sum/?tab=Description
 Difficulty: Medium
 Tags:       {Array}, {Two Pointers}, {Binary Search}
 Company:    Facebook
 
 Notes:
 Given an array of n positive integers and a positive integer s, 
 find the minimal length of a contiguous subarray of which the sum ≥ s. 
 If there isn't one, return 0 instead.

 For example, given the array [2,3,1,2,4,3] and s = 7,
 the subarray [4,3] has the minimal length under the problem constraint.
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = INT_MAX, sum = 0;
        int start = 0, end = 0;
        while (end < nums.size()) {
            sum += nums[end];
            if (sum < s) {
                end++; continue;
            }
            while (start <= end) {
                if (sum - nums[start] >= s) {
                    sum -= nums[start++];
                } else {
                    break;
                }
            }
            res = min(res, end-start+1);
            end++;
        }
        return sum < s ? 0 : res;
    }
};

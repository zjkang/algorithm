/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Size Subarray Sum Equals k
 Source:     https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/#/description
 Difficulty: Medium
 Tags:       {Hash Table}
 Company:    Palantir, Facebook
 
 Notes:
 Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> dict;
        dict[0] = -1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (dict.count(sum-k)) {
                res = max(res, i - dict[sum-k]);
            }
            if (!dict.count(sum)) {
                dict[sum] = i;
            }
        }
        return res;
    }
};


/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Increasing Subsequence
 Source:     https://leetcode.com/problems/longest-increasing-subsequence/?tab=Description
 Tags:       {Dynamical Programming}, {Binary Search}
 Company:    Microsoft

 Notes:
 Given an unsorted array of integers, find the length of longest increasing subsequence.

 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
 Note that there may be more than one LIS combination, it is only necessary for you to return the length.

 Your algorithm should run in O(n2) complexity.

 Follow up: Could you improve it to O(n log n) time complexity?
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1);
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            res = max(dp[i], res);
        }
        return res;
    }
    // O(n log n) 
    int lengthOfLIS(vector<int>& nums) {
        // refer https://leetcode.com/problems/longest-increasing-subsequence/#/solution
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return res.size();
    }
};

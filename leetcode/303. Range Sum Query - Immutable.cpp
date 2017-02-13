/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Range Sum Query - Immutable
 Source:     https://leetcode.com/problems/range-sum-query-immutable/
 Difficulty: Easy
 Tags:       {Dynamic Programming}
 Company:    Palantir
 
 Notes:
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

 Example:
 Given nums = [-2, 0, 3, -5, 2, -1]

 sumRange(0, 2) -> 1
 sumRange(2, 5) -> -1
 sumRange(0, 5) -> -3
 Note:
 You may assume that the array does not change.
 There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(vector<int> &nums) : d_dp(nums) {
        for(int i = 1; i < nums.size(); ++i) {
            d_dp[i] = d_dp[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return d_dp[j];
        else return d_dp[j] - d_dp[i-1];
    }
private:
    vector<int> d_dp;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);

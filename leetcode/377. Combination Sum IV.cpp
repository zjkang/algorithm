/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Combination Sum IV
 Source:     https://leetcode.com/problems/combination-sum-iv/
 Difficulty: Medium
 Tags:       Dynamical Programming
 Company:    {Google}, {Snapchat}, {Facebook}
 
 Notes:
 Given an integer array with all positive numbers and no duplicates, 
 find the number of possible combinations that add up to a positive integer target.

 Example:

 nums = [1, 2, 3]
 target = 4

 The possible combination ways are:
 (1, 1, 1, 1)
 (1, 1, 2)
 (1, 2, 1)
 (1, 3)
 (2, 1, 1)
 (2, 2)
 (3, 1)

 Note that different sequences are counted as different combinations.

 Therefore the output is 7.
 Follow up:
 What if negative numbers are allowed in the given array?
 How does it change the problem?
 What limitation we need to add to the question to allow negative numbers?
 */

class Solution {
public:
    void dfs(vector<int>& nums, int target, map<int, int>& map) {
        if (map.count(target)) {
            return;
        }
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > target) break;
            if (nums[i] == target) {
                res += 1;
            } else {
                dfs(nums, target - nums[i], map);
                res += map[target - nums[i]];
            }
        }
        map[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        int res = 0, size = nums.size();
        map<int, int> map;
        sort(nums.begin(), nums.end());
        dfs(nums, target, map);
        return map[target];
    }
};


/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Target Sum
 Source:     https://leetcode.com/problems/target-sum/
 Difficulty: Medium
 Tags:       {Depth-first Search}, {Dynamic Programming}
 Company:    {Google}, {Facebook}

 Notes:
 You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. 
 Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

 Find out how many ways to assign symbols to make sum of integers equal to target S.

 Example 1:
 Input: nums is [1, 1, 1, 1, 1], S is 3. 
 Output: 5
 Explanation: 

 -1+1+1+1+1 = 3
 +1-1+1+1+1 = 3
 +1+1-1+1+1 = 3
 +1+1+1-1+1 = 3
 +1+1+1+1-1 = 3

 There are 5 ways to assign symbols to make the sum of nums be target 3.
 Note:
 The length of the given array is positive and will not exceed 20.
 The sum of elements in the given array will not exceed 1000. 
 Your output answer is guaranteed to be fitted in a 32-bit integer.
 Hide Company Tags
*/

class Solution {
public:
    int dfs(vector<int>& nums, int start, int end, int S) {
        if (start == end) {
            return (S == 0 && nums[start] == 0) ? 2 : ((nums[start] == S || nums[start] == -S) ? 1 : 0);
        }
        int n1 = dfs(nums, start+1, end, S-nums[start]);
        int n2 = dfs(nums, start+1, end, S+nums[start]);
        return n1 + n2;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()) {
            return 0;
        }
        return dfs(nums, 0, nums.size()-1, S); 
    }
};
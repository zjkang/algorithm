/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Increasing Subsequences
 Source:     https://leetcode.com/problems/increasing-subsequences/
 Difficulty: Medium
 Tags:       {Depth-first Search}
 Company:    Yahoo

 Notes:
 Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
 and the length of an increasing subsequence should be at least 2 .

 Example:
 Input: [4, 6, 7, 7]
 Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
 Note:
 The length of the given array will not exceed 15.
 The range of integer in the given array is [-100,100].
 The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
*/

class Solution {
public:
    void dfs(vector<int>& nums, int start, vector<int>& oneRes, vector<vector<int>>& res) {
        if (start == nums.size()) {
            return;
        }
        unordered_set<int> set; // use hash to record duplicates
        for (int i = start; i < nums.size(); ++i) {
            if (!set.count(nums[i])) {
                if (oneRes.empty()) {
                    oneRes.push_back(nums[i]);
                } else if (nums[i] >= oneRes.back()) {
                    oneRes.push_back(nums[i]);
                    res.push_back(oneRes);
                } else {
                    continue;
                }
                set.insert(nums[i]);
                dfs(nums, i+1, oneRes, res);
                oneRes.pop_back();   
            }
        }
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() <= 1) {
            return res;
        }
        vector<int> oneRes;
        dfs(nums, 0, oneRes, res);
        return res;
    }
};

/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Contiguous Array
 Source:     https://leetcode.com/problems/contiguous-array/?tab=Description
 Difficulty: Medium
 Company:    Facebook
 Tags:       {Hash Table}

 Notes:
 Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

 Example 1:
 Input: [0,1] 
 Output: 2
 Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

 Example 2:
 Input: [0,1,0]
 Output: 2
 Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
 Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    // ref: https://discuss.leetcode.com/topic/79906/easy-java-o-n-solution-presum-hashmap
    // The idea is to change 0 in the original array to -1. Thus, if we find SUM[i, j] == 0 then we know there are even number
    // of -1 and 1 between index i and j. Also put the sum to index mapping to a HashMap to make search faster.
    int findMaxLength(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        int res = 0, sum = 0;
        map<int, int> map;
        map[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (map.count(sum)) {
                res = max(res, i - map[sum]);
            } else {
                map[sum] = i;
            }
        }
        return res;
    }
};
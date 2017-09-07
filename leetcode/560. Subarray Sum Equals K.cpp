/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Subarray Sum Equals K
 Source:     https://leetcode.com/problems/subarray-sum-equals-k/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Array, Map}

 Notes:
 Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

 Example 1:
 Input:nums = [1,1,1], k = 2
 Output: 2
 Note:
 The length of the array is in range [1, 20,000].
 The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

class Solution {
public:
    // sum[i,j] == k <==> presum[j] - presum[i-1] == k
    // map<presum, freq>
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0, presum = 0;
        unordered_map<int,int> hash;
        hash[0] = 1; // dummy presum [0, A[0], A[0:1],....]
        for (int i = 0; i < nums.size(); ++i) {
            presum += nums[i];
            int remain = presum - k;
            if (hash.count(remain)) {
                res += hash[remain];
            }
            hash[presum]++;
        }
        return res;
    }
};

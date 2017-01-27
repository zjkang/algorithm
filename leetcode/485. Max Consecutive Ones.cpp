/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Max Consecutive Ones
 Source:     https://leetcode.com/problems/max-consecutive-ones/
 Difficulty: Easy
 Tags:       {Array}
 Company:    {Google}

 Notes:
 Given a binary array, find the maximum number of consecutive 1s in this array.

 Example 1:
 Input: [1,1,0,1,1,1]
 Output: 3
 Explanation: The first two digits or the last three digits are consecutive 1s.
 The maximum number of consecutive 1s is 3.
 Note:

 The input array will only contain 0 and 1.
 The length of input array is a positive integer and will not exceed 10,000
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                res = max(res, sum);
                sum = 0;
            } else {
                sum++;
            }
        }
        res = max(res, sum);
        return res;
    }
};



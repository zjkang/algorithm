/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Shortest Unsorted Continuous Subarray
 Source:     https://leetcode.com/problems/shortest-unsorted-continuous-subarray/#/description
 Difficulty: Easy
 Company:    Google
 Tags:       {Array}

 Notes:
 Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

 You need to find the shortest such subarray and output its length.

 Example 1:
 Input: [2, 6, 4, 8, 10, 9, 15]
 Output: 5
 Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

 Note:
 Then length of the input array is in range [1, 10,000].
 The input array may contain duplicates, so ascending order here means <=.
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // *Find first decreasing number i from left hand, first increasing number j from right hand.
        // *Sort arrays between [i, j] and find min/max between.
        // *Find first number < min starting i, and first number > max starting j.
        // e.g., 2 5 8 3 10 9 15
        int res = 0;
        int left = 0, right = nums.size() - 1;
        while (left + 1 < nums.size() && nums[left] <= nums[left+1]) left++;
        while (right - 1 >= 0 && nums[right] >= nums[right-1]) right--;
        
        int maxVal = INT_MIN, minVal = INT_MAX;
        for (int i = left; i <= right; ++i) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }
        
        while (left >= 0 && nums[left] > minVal) left--;
        while (right < nums.size() && nums[right] < maxVal) right++;
        
        return right-left-1 < 0 ? 0 : right-left-1;
        
    }
};
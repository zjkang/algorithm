/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Maximum Distance in Arrays
 Source:     https://leetcode.com/problems/maximum-distance-in-arrays/#/description
 Difficulty: Easy
 Company:    Yahoo
 Tags:       {Array, Hash Table}

 Notes:
 Given m arrays, and each array is sorted in ascending order. Now you can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a-b|. Your task is to find the maximum distance.

 Example 1:
 Input: 
 [[1,2,3],
  [4,5],
  [1,2,3]]
 Output: 4
 Explanation: 
 One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
 Note:
 Each given array will have at least 1 number. There will be at least two non-empty arrays.
 The total number of the integers in all the m arrays will be in the range of [2, 10000].
 The integers in the m arrays will be in the range of [-10000, 10000].
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = INT_MIN;
        int minVal = INT_MIN, maxVal = INT_MAX;
        for (auto nums : arrays) {
            if (minVal == INT_MIN && maxVal == INT_MAX) {
                minVal = nums.front();
                maxVal = nums.back();
            } else {
                res = max({res, abs(nums.back()-minVal), abs(nums.front()-maxVal)});
                minVal = min(minVal, nums.front());
                maxVal = max(maxVal, nums.back());
            }
        }
        return res;
    }
};
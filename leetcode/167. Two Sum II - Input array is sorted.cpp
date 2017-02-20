/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Two Sum II - Input array is sorted
 Source:     https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?tab=Description
 Difficulty: Easy
 Tags:       {Array}, {Two Pointers}, {Binary Search}
 Company:    Amazon

 Notes:
 Given an array of integers that is already sorted in ascending order, 
 find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. 
 Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution and you may not use the same element twice.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2 
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                vector<int> res = {i+1, j+1};
                return res;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {-1, -1};
    }
};
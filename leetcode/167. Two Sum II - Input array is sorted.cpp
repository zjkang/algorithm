/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu 
 Problem:    Two Sum II - Input array is sorted
 Source:     https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
 
 Notes:  
 Given an array of integers that is already sorted in ascending order, 
 find two numbers such that they add up to a specific target number.
 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. 
 Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution: Two Pointers Binary Search
*/

// 20ms
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }
        return {l + 1, r + 1};
    }
};


// 13ms
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i = 0; i < numbers.size()-1; ++i) {
            int idx = binSearch(numbers, target - numbers[i], i);
            if (idx != -1) {
                return {i+1, idx+1};
            }
        }    
        return {-1, -1};
    }

    int binSearch(vector<int> &numbers, int target, int start) {
        int l = start + 1, r = numbers.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target == numbers[m]) return m;
            else if (target < numbers[m]) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};

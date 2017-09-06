/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu 
 Problem:    Two Sum
 Source:     https://leetcode.com/problems/two-sum/description/
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.
 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 You may assume that each input would have exactly one solution.

 Input: numbers = {2, 7, 11, 15}, target = 9
 Output: index1 = 1, index2 = 2

 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
 */

class Solution {
public:   
    bool compare(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
    }

    //time: O(nlogn). pair<val,index> nums
    vector<int> twoSum(vector<int> &numbers, int target) { 
        vector<pair<int, int> > nums(numbers.size());
        for (int i = 0; i < numbers.size(); ++i) {
            nums[i] = {numbers[i], i+1};
        }
        sort(nums.begin(), nums.end(), compare); // O(nlogn)

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l].first + nums[r].first;
            if (sum == target) {
                break;
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        vector<int> res;
        res.push_back(min(nums[l].second, nums[r].second));
        res.push_back(max(nums[l].second, nums[r].second));
        return res;
    }
};

//hash-table one-pass solution
class Solution {
public:  
    vector<int> twoSum(vector<int> &numbers, int target) { 
        unordered_map<int, int> map; // <value, index> 
        for (int i = 0; i < numbers.size(); ++i) {
            int val = target - numbers[i];
            if (map.count(val)) {
                vector<int> res = {map[val], i+1};
                return res;
            } else {
                map[numbers[i]] = i + 1;
            }
        }
        return {-1,-1};
    }
};
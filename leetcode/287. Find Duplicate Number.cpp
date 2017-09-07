/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find the Duplicate Number
 Source:     https://leetcode.com/problems/find-the-duplicate-number/?tab=Description
 Tags:       {Binary Search}, {Array}, {Two Pointers}
 Company:    Bloomberg

 Notes:
 Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
 prove that at least one duplicate number must exist. 
 Assume that there is only one duplicate number, find the duplicate one.

 Note:
 You must not modify the array (assume the array is read only).
 You must use only constant, O(1) extra space.
 Your runtime complexity should be less than O(n2).
 There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (auto i : nums) {
                if (i <= mid) {
                    count++;
                }
            }
            if (count <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

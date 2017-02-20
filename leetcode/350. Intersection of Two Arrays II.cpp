/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Intersection of Two Arrays II
 Source:     https://leetcode.com/problems/intersection-of-two-arrays-ii/?tab=Description
 Difficulty: Easy
 Tags:       {Binary Search}, {Hash Table}, {Two Pointers}, {Sort}
 Company:    Two Sigma
 
 Notes:
 Given two arrays, write a function to compute their intersection.

 Example:
 Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

 Note:
 Each element in the result must be unique.
 The result can be in any order.

 Follow up:
 What if the given array is already sorted? How would you optimize your algorithm?
 What if nums1's size is small compared to nums2's size? Which algorithm is better?
 What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int s1 = 0, s2 = 0;
        while (s1 < nums1.size() && s2 < nums2.size()) {
            if (nums1[s1] == nums2[s2]) {
                if (res.size() == 0 || (nums1[s1] != res[res.size()-1])) {
                    res.push_back(nums1[s1]);
                }
                s1++; 
                s2++;
            } else if (nums1[s1] < nums2[s2]) {
                s1++;
            } else {
                s2++;
            }
        }
        return res;
    }
};




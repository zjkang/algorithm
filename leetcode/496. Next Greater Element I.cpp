/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Next Greater Element I
 Source:     https://leetcode.com/problems/next-greater-element-i/
 Difficulty: Easy
 Tags:       {Stack}
 Company:    Google

 Notes:
 You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. 
 Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

 The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
 If it does not exist, output -1 for this number.

 Example 1:
 Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 Output: [-1,3,-1]
 Explanation:
     For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
     For number 1 in the first array, the next greater number for it in the second array is 3.
     For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
 
 Example 2:
 Input: nums1 = [2,4], nums2 = [1,2,3,4].
 Output: [3,-1]
 Explanation:
     For number 2 in the first array, the next greater number for it in the second array is 3.
     For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
 Note:
 All elements in nums1 and nums2 are unique.
 The length of both nums1 and nums2 would not exceed 1000.
*/

class Solution {
public:
    // Use stack to store a decreasing sequences of nums.
    // Refer http://bookshadow.com/weblog/2017/02/05/leetcode-next-greater-element-i/
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> map; // <val, next greater val>
        for (int n : nums) {
            while (!s.empty() && s.top() < n) { // stack to add next greater val
                map[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (int n : findNums) {
            res.push_back(map.count(n) ? map[n] : -1);
        }
        return res;
    }
};
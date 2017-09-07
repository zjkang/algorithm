/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Next Greater Element II
 Source:     https://leetcode.com/problems/next-greater-element-ii/
 Difficulty: Medium
 Tags:       {Stack}
 Company:    Google

 Notes:
 Given a circular array (the next element of the last element is the first element of the array), 
 print the Next Greater Number for every element. 
 The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, 
 which means you could search circularly to find its next greater number. 
 If it doesn't exist, output -1 for this number.

 Example 1:
 Input: [1,2,1]
 Output: [2,-1,2]
 Explanation: The first 1's next greater number is 2; 
 The number 2 can't find next greater number; 
 The second 1's next greater number needs to search circularly, which is also 2.
 Note: The length of given array won't exceed 10000.
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return {};
        vector<int> res(size, -1);
        vector<bool> visited(size, false);
        int i = 0;
        stack<int> s;
        while (1) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            if (!s.empty() && s.top() == i) { // traverse back to the same index
                break;
            }
            if (!visited[i]) {
                s.push(i); // guarantee push to stack once
                visited[i] = true;
            }
            i = (i+1) % size;
        }
        return res;
    }
};
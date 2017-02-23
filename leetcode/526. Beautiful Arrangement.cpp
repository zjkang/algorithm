/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Beautiful Arrangement
 Source:     https://leetcode.com/problems/beautiful-arrangement/?tab=Description
 Difficulty: Medium
 Company:    Google
 Tags:       {Backtracking}

 Notes:
 Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array 
 that is constructed by these N numbers successfully if one of the following is true for the ith position (1 ≤ i ≤ N) in this array:

 The number at the ith position is divisible by i.
 i is divisible by the number at the ith position.
 Now given N, how many beautiful arrangements can you construct?

 Example 1:
 Input: 2
 Output: 2
 Explanation: 

 The first beautiful arrangement is [1, 2]:

 Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

 Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

 The second beautiful arrangement is [2, 1]:

 Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

 Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
 Note:
 N is a positive integer and will not exceed 15.
 Hide Company Tags
*/

class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& available, int count, int& res) {
        int N = nums.size();
        if (count == N) {
            res++;
            return;
        }
        for (int i = 0; i < N; ++i) {
            if (available[i] && ((nums[i] % (count+1) == 0) || ((count+1) % nums[i] == 0))) {
                available[i] = false;
                dfs(nums, available, count+1, res);
                available[i] = true;
            }
        }
    }

    int countArrangement(int N) {
        if (N == 1) {
            return 1;
        }
        
        vector<int> nums(N, 0);
        vector<bool> available(N, true);
        for (int i = 0; i < N; ++i) {
            nums[i] = i + 1;
        }
        
        int res = 0;
        dfs(nums, available, 0, res);
        return res;
    }
};
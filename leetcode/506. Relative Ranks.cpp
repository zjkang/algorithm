/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Relative Ranks
 Source:     https://leetcode.com/problems/relative-ranks/
 Difficulty: Easy
 Company:    {Google}

 Notes:
 Given scores of N athletes, find their relative ranks and the people with the top three highest scores, 
 who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".

 Example 1:
 Input: [5, 4, 3, 2, 1]
 Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 Explanation: The first three athletes got the top three highest scores, 
 so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
 For the left two athletes, you just need to output their relative ranks according to their scores.
 Note:
 N is a positive integer and won't exceed 10,000.
 All the scores of athletes are guaranteed to be unique.
*/

class Solution {
public:
    bool static comparison(const pair<int,int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int,int>> indexNums; // <index, score>
        for (int i = 0; i < nums.size(); ++i) {
            indexNums.push_back({i, nums[i]});
        }
        sort(indexNums.begin(), indexNums.end(), comparison);
        vector<string> res(nums.size(), "");
        for (int i = 0; i < indexNums.size(); ++i) {
            if (i == 0) {
                res[indexNums[i].first] = "Gold Medal";
            } else if (i == 1) {
                res[indexNums[i].first] = "Silver Medal";
            } else if (i == 2) {
                res[indexNums[i].first] = "Bronze Medal";
            } else {
                res[indexNums[i].first]  = to_string(i+1);
            }
        }
        return res;
    }
};

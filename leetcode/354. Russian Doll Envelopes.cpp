/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Russian Doll Envelopes
 Source:     https://leetcode.com/problems/russian-doll-envelopes/#/description
 Difficulty: Hard
 Tags:       {Binary Search, Dynamic Programming}
 Company:    Google
 
 Notes:
 You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
 One envelope can fit into another if and only 
 if both the width and height of one envelope is greater than the width and height of the other envelope.

 What is the maximum number of envelopes can you Russian doll? (put one inside other)

 Example:
 Given envelopes = [[5,4],[6,4],[6,7],[2,3]], 
 the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

class Solution {
public:
    static bool compare(const pair<int,int>& lhs, const pair<int,int>& rhs) {
        if (lhs.first == rhs.first) return lhs.second > rhs.second;
        return lhs.first < rhs.first;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<int> dp;
        sort(envelopes.begin(), envelopes.end(), compare);
        // refer longest increasing subsequence O(nlogn)
        for (int i = 0; i < envelopes.size(); ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (it == dp.end()) {
                dp.push_back(envelopes[i].second);
            } else {
                *it = envelopes[i].second;
            }
        }
        return dp.size();
    }
};





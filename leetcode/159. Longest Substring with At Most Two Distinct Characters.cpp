/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Substring with At Most Two Distinct Characters 
 Source:     https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/#/description
 Difficulty: Hard
 Topic:      Hash Table, Two Pointers, String
 Company:    Google

 Notes:
 Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
 For example, Given s = “eceba”,
 T is "ece" which its length is 3.
*/

class Solution {
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, count = 0;
        vector<int> need(256, 0);
        int i = 0, j = 0;
        while (j < s.size()) {
            if (need[s[j]] == 0) count++;
            need[s[j]]++;
            if (count <= 2) {
                j++; 
                continue;
            }
            res = max(res, j - i);
            while (i < j && count == 3) {
                need[s[i]]--;
                if (need[s[i]] == 0) count--;
                i++;
            }
            j++;
        }
        res = max(res, j - i);
        return res;
    }
};

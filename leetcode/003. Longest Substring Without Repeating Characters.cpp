/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Substring Without Repeating Characters
 Source:     https://leetcode.com/problems/longest-substring-without-repeating-characters/#/description
 Difficulty: Medium
 Topic:      {Hash Table, Two Pointers, String}
 Company:    Amazon, Adobe, Bloomberg, Yelp

 Notes:
 Given a string, find the length of the longest substring without repeating characters.

 Examples:

 Given "abcabcbb", the answer is "abc", which the length is 3.
 Given "bbbbb", the answer is "b", with the length of 1.
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, 
 "pwke" is a subsequence and not a substring.

 Solution: Pay attention when moving the 'start' pointer forward.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0, end = 0;
        int N = s.size();
        vector<bool> found(256, false);
        while (end < N) { // slinding window (2 pointers)
            if (!found[s[end]]) {
                found[s[end++]] = true;
                continue;
            }
            res = max(end - start, res);
            while (found[s[end]]) {
                found[s[start++]] = false;
            }
        }
        res = max(res, end - start);
        return res;
    }
};

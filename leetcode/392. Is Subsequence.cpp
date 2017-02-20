/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Is Subsequence
 Source:     https://leetcode.com/problems/is-subsequence/?tab=Description
 Difficulty: Medium
 Tags:       {Binary Search}, {Dynamical Programming}, {Greedy}
 Company:    Pinterest
 
 Notes:
 Given a string s and a string t, check if s is subsequence of t.
 You may assume that there is only lower case English letters in both s and t. 
 t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

 A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

 Example 1:
 s = "abc", t = "ahbgdc"
 Return true.

 Example 2:
 s = "axc", t = "ahbgdc"
 Return false.

 Follow up:
 If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. 
 In this scenario, how would you change your code?
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                ++i; ++j;
            } else {
                ++j;
            }
        }
        return i == s.size();
    }
};

// Binary search
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //build a record the index of each char in t
        vector<vector<int>> record(26);
        //add indexs
        for(int i = 0; i < t.size(); i++) {
            record[t[i]-'a'].push_back(i);
        }
        //check if each char in s is in the legal place
        int index = -1;
        for(int i = 0; i < s.size(); i++) {
            auto iter = upper_bound(record[s[i]-'a'].begin(), record[s[i]-'a'].end(), index);
            if(iter == record[s[i]-'a'].end()) return false;
            index = *iter;
        }
        return true;
    }
};

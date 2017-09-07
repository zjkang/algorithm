/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Minimum Window Substring
 Source:     http://oj.leetcode.com/problems/minimum-window-substring/
 Difficulty: Hard
 Topic:      Hash Table, Two Pointers, String
 Company:    Linkedin, Snapchat, Uber, Facebook

 Notes:
 Given a string S and a string T, find the minimum window in S which will contain all the 
 characters in T in complexity O(n).
 For example,
 S = "ADOBECODEBANC"
 T = "ABC"
 Minimum window is "BANC".
 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".
 If there are multiple such windows, you are guaranteed that there will always be only one unique 
 minimum window in S.
 Solution: Use two pointers: start and end. 
           First, move 'end'. After finding all the needed characters, move 'start'.
           Use array as hashtable.
*/

class Solution {
public:
    string minWindow(string S, string T) {
        int N = S.size(), M = T.size();
        if (N < M) return "";
        int need[256] = {0}, find[256] = {0};
        for (int i = 0; i < M; ++i) need[T[i]]++;            
        int count = 0; 
        int resStart = -1, resEnd = N;
        for (int start = 0, end = 0; end < N; ++end) {
            if (need[S[end]] == 0) continue;   
            if (++find[S[end]] <= need[S[end]]) count++;
            if (count != M) continue;          
            // move 'start'
            for (; start < end; ++start) {
                if (need[S[start]] == 0) continue;
                if (find[S[start]] == need[S[start]]) break;
                find[S[start]]--;
            }            
            // update min window
            if (end - start < resEnd - resStart) {
                resStart = start;
                resEnd = end;
            }
        }
        return (resStart == -1) ? "" : S.substr(resStart, resEnd - resStart + 1);
    }
};
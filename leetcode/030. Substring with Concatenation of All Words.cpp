/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Substring with Concatenation of All Words
 Source:     https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description
 Difficulty: Hard
 Topic:      {Hash Table, Two Pointers, String}
 Company:

 Notes:
 You are given a string, S, and a list of words, L, that are all of the same length. Find all 
 starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
 and without any intervening characters.
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 
 (order does not matter).
 Solution: similar to obtain the statistics of numbers of words in hash table. 
 Time complexity: O(n^2). 
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if (S.empty() || L.empty()) return {};
        int M = S.size(), N = L.size(), K = L[0].size();
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        for (int i = 0; i < N; ++i) need[L[i]]++; 
        vector<int> res;
        for (int i = 0; i <= M - N * K; ++i) {
            found.clear();
            int j = 0;
            for (; j < N; ++j) {
                string s = S.substr(i + j * K, K);
                if (!need.count(s) || ++found[s] > need[s]) break;                    
            }
            if (j == N) { // found all words in a string
                res.push_back(i);
            }
        }
        return res;
    }
};

/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Word in Dictionary through Deleting
 Source:     https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Two Pointers, Sort}

 Notes:
 Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.

 Example 1:
 Input:
 s = "abpcplea", d = ["ale","apple","monkey","plea"]

 Output: 
 "apple"
 Example 2:
 Input:
 s = "abpcplea", d = ["a","b","c"]
 
 Output: 
 "a"
 Note:
 All the strings in the input will only contain lower-case letters.
 The size of the dictionary won't exceed 1,000.
 The length of all the strings in the input won't exceed 1,000.
*/

class Solution {
public:
    bool isMatch(const string& s, const string& word) {
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == word[index]) index++;
            if (index == word.size()) return true;
        }
        return false;
    }
    
    struct Compare {
        bool operator()(const string& a, const string& b) const {
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        }  
    };

    string findLongestWord(string s, vector<string>& d) {
        set<string, Compare> dict;
        for (auto i : d) {
            dict.insert(i);
        }
        for (auto i : dict) {
            if (isMatch(s, i)) return i;
        }
        return "";
    }
};

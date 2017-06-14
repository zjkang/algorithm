/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Longest Uncommon Subsequence II
 Source:     https://leetcode.com/problems/longest-uncommon-subsequence-ii/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {String}

 Notes:
 Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.

 A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.

 The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.

 Example 1:
 Input: "aba", "cdc", "eae"
 Output: 3
 Note:

 All the given strings' lengths will not exceed 10.
 The length of the given list will be in the range of [2, 50].
*/

class Solution {
public:
    struct Compare {
        bool operator()(const string& l, const string& r) const {
            return l.size() == r.size() ? l > r : l.size() > r.size(); // strictly comparison
        }   
    };
    
    bool isSubsequence(const string& l, const string& s) {
        int j = 0;
        for (int i = 0; i < l.size(); ++i) {
            if (l[i] == s[j]) {
                j++;
            }
            if (j == s.size()) {
                return true;
            }
        }
        return false;
    }

    int findLUSlength(vector<string>& strs) {
        // *not in no duplicated strings 
        // *maybe in one of strings, but not substring
        if (strs.size() == 1) return -1;
        map<string, int, Compare> hash;
        for (int i = 0; i < strs.size(); ++i) {
            hash[strs[i]]++;
        }
        
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            if (it->second == 1) {
                bool exist = true;
                for (auto next = hash.begin(); next != it; ++next) {
                    if (isSubsequence(next->first, it->first)) {
                        exist = false;
                        break;
                    }
                }
                if (exist) return it->first.size();
            }   
        }
        return -1;
    }
};


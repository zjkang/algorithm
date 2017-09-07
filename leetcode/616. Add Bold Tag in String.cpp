/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Add Bold Tag in String
 Source:     https://leetcode.com/problems/add-bold-tag-in-string/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {String}

 Notes:
 Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. 
 If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. 
 Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

 Example 1:
 Input: 
 s = "abcxyz123"
 dict = ["abc","123"]
 Output:
 "<b>abc</b>xyz<b>123</b>"

 Example 2:
 Input: 
 s = "aaabbcc"
 dict = ["aaa","aab","bc"]
 Output:
 "<b>aaabbc</b>c"
 
 Note:
 The given dict won't contain duplicates, and its length won't exceed 100.
 All the strings in input have length in range [1, 1000].
*/

class Solution {
public:
    class Compare {
      public:
        bool operator() (const string& l, const string& r) const {
            if (l.length() == r.length()) return l < r;
            else return l.length() > r.length();
        }       
    };
    
    string addBoldTag(string s, vector<string>& dict) {
        set<string, Compare> hash;
        for (auto w : dict) {
            hash.insert(w);
        }
    
        vector<pair<int,int>> tags; // {start, end}
        int start = -1, end = -1;
        int tstart = 0, tend = -1;
        for (; tstart < s.size(); ++tstart) {
            tend = -1;
            for (auto w : hash) {
                if (tstart + w.length() <= s.size() && s.substr(tstart, w.length()) == w) {
                    tend = tstart + w.length();
                    break;
                }
            }
            // similar to interval merge
            if (tend != -1) {
                if (start == -1) {
                    start = tstart;
                    end = tend;
                } else if (tstart <= end) {
                    end = max(end, tend);
                } else {
                    tags.push_back({start, end});
                    start = tstart;
                    end = tend;
                }
            }
            if (tend == s.size()) {
                break;
            }
        }
        
        if (start != -1) { // push the last one
            tags.push_back({start, end});
        }
        
        // generate result
        if (tags.empty()) return s;
        
        string res;
        res.append(s.substr(0, tags[0].first));
        for (int i = 0; i < tags.size(); ++i) {
            if (i != 0) {
                res.append(s.substr(tags[i-1].second, tags[i].first - tags[i-1].second)); // insert between
            }
            res.append("<b>");
            res.append(s.substr(tags[i].first, tags[i].second - tags[i].first));
            res.append("</b>");    
        }
        res.append(s.substr(tags.back().second));
        
        return res;
    }
};

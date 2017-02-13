/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Keyboard Row
 Source:     https://leetcode.com/problems/keyboard-row/
 Difficulty: Easy
 Tags:       {Hash Table}
 Company:    Mathworks

 Notes:
 Given a List of words, return the words that can be typed using letters of alphabet on 
 only one row's of American keyboard like the image below.

 Example 1:
 Input: ["Hello", "Alaska", "Dad", "Peace"]
 Output: ["Alaska", "Dad"]
 Note:
 You may use one character in the keyboard more than once.
 You may assume the input string will only contain letters of alphabet.
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if (words.empty()) return {};
        unordered_map<char,int> map;
        vector<string> letters = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for (int i = 0; i < letters.size(); ++i) {
            for (auto c : letters[i]) {
                map[c] = i;
            }
        }
        vector<string> res;
        for (auto s : words) {
            int n = 0;
            bool sameLine = true;
            for (int i = 0; i < s.size(); ++i) {
                if (i == 0) {
                    n = map[tolower(s[i])];
                } else if (n != map[tolower(s[i])]) {
                    sameLine = false;
                    break;
                }
            }
            if (sameLine) res.push_back(s);
        }
        return res;
    }
};
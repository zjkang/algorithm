/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Detect Capital
 Source:     https://leetcode.com/problems/detect-capital/?tab=Description
 Difficulty: Easy
 Company:    Google
 Tags:       {String}

 Notes:
 Given a word, you need to judge whether the usage of capitals in it is right or not.

 We define the usage of capitals in a word to be right when one of the following cases holds:

 All letters in this word are capitals, like "USA".
 All letters in this word are not capitals, like "leetcode".
 Only the first letter in this word is capital if it has more than one letter, like "Google".
 Otherwise, we define that this word doesn't use capitals in a right way.
 
 Example 1:
 Input: "USA"
 Output: True

 Example 2:
 Input: "FlaG"
 Output: False
*/

// Consider all test cases.
class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty()) return true; // non-empty word
        bool firstUpper = false, secondUpper = false;
        for (int i = 0; i < word.size(); ++i) {
            if (i == 0) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    firstUpper = true;
                }
            } else if (word[i] >= 'a' && word[i] <= 'z') {
                if (firstUpper && secondUpper) return false;
            } else {
                if (i == 1) secondUpper = true;
                if (!firstUpper || !secondUpper) return false;
            }
        }
        return true;
    }
};

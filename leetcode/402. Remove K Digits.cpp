/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Remove K Digits
 Source:     https://leetcode.com/problems/remove-k-digits/?tab=Description
 Difficulty: Medium
 Tags:       {Stack}, {Greedy}
 Company:    Google, Snapchat
 
 Notes:
 Given a non-negative integer num represented as a string, 
 remove k digits from the number so that the new number is the smallest possible.

 Note:
 The length of num is less than 10002 and will be ≥ k.
 The given num does not contain any leading zero.
 Example 1:

 Input: num = "1432219", k = 3
 Output: "1219"
 Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
 Example 2:

 Input: num = "10200", k = 1
 Output: "200"
 Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
 Example 3:

 Input: num = "10", k = 2
 Output: "0"
 Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeLeadingZeros(const string& s) {
        if (s.empty()) return "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '0') {
                return s.substr(i);
            }
        }
        return "0";
    }
    
    string removeKdigits(string num, int k) {
        if (num.size() <= k || num.size() == 0) return "0";
        // stack is used to preserve a increasing number vector.
        // consider element order in stack
        stack<int> s;
        int counter = 0, l = 0;
        while (l < num.size()) {
            if (s.empty() || num[s.top()] <= num[l]) { // remove local max
                s.push(l++);
            } else {
                num.erase(--l, 1);
                s.pop();
                counter++;
                if (counter == k) break;
            } 
        }
        if (counter == k) return removeLeadingZeros(num);
        else return removeLeadingZeros(num.substr(0, num.size() - (k - counter)));
    }
};
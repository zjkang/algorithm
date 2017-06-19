/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Student Attendance Record I
 Source:     https://leetcode.com/problems/student-attendance-record-i/#/description
 Difficulty: Easy
 Company:    Google
 Tags:       {String}

 Notes:
 You are given a string representing an attendance record for a student. The record only contains the following three characters:

 'A' : Absent.
 'L' : Late.
 'P' : Present.
 A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

 You need to return whether the student could be rewarded according to his attendance record.
 
 Example 1:
 Input: "PPALLP"
 Output: True
 Example 2:
 Input: "PPALLL"
 Output: False
*/

class Solution {
public:
    bool checkRecord(string s) {
        int numAbsent = 0, numLate = 0;
        int size = s.length();
        for (int i = 0; i < size; ++i) {
            if (s[i] == 'A') {
                numAbsent++;
                if (numAbsent > 1) return false;
            } else if (i != 0 && (i != 1) && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') {
                return false;
            }
        }
        return true;
    }
};

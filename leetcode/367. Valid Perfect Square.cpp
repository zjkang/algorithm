/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Valid Perfect Square
 Source:     https://leetcode.com/problems/valid-perfect-square/?tab=Description
 Difficulty: Easy
 Tags:       {Binary Search}, {Math}
 Company:    Linkedin
 
 Notes:
 Given a positive integer num, write a function which returns True if num is a perfect square else False.
 Note: Do not use any built-in library function such as sqrt.

 Example 1:
 Input: 16
 Returns: True

 Example 2:
 Input: 14
 Returns: False
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int start = 1, end = num;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (num % mid == 0 && mid == num / mid) return true;
            else if (mid < num / mid) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
};
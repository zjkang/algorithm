/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find First Bad Version
 Source:     https://leetcode.com/problems/first-bad-version/?tab=Description
 Tags:       {Binary Search}
 Company:    Facebook

 Notes:
You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether 
 * the kth code version is bad or not.
*/
class Solution {
public:
    int findFirstBadVersion(int n) {
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (VersionControl::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (VersionControl::isBadVersion(start)) return start;
        if (VersionControl::isBadVersion(end)) return end;
        return -1; // no bad version exists!
    }
};



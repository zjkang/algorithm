/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Search for a Range
 Source:     https://leetcode.com/problems/search-for-a-range/?tab=Description
 Tags:       {Binary Search}, {Array}
 Company:    Linkedin

 Notes:
 Given a sorted array of integers, find the starting and ending position of a given target value.
 Your algorithm's runtime complexity must be in the order of O(log n).
 If the target is not found in the array, return [-1, -1].
 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].
 Solution: It takes O(lgN) to find both the lower-bound and upper-bound.
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start, end, mid;
        vector<int> bound(2, 0);
        // search for left bound
        start = 0; end = n - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (A[start] == target) {
            bound[0] = start;
        } else if (A[end] == target) {
            bound[0] = end;
        } else {
            return {-1, -1};
        }
        // search for right bound
        start = 0; end = n - 1;
        while (start + 1 < end) {
            mid = start + (end - start) / 2;
            if (A[mid] == target) {
                start = mid;
            } else if (A[mid] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (A[end] == target) {
            bound[1] = end;
        } else if (A[start] == target) {
            bound[1] = start;
        } else {
            return {-1,-1};
        }
        return bound;
    }
};

/*
 Extension: 找到第一个值或者最后一个值
 Note:
 Binary search is a famous question in algorithm.
 For a given sorted array (ascending order) and a target number, 
 find the first index of this number in O(log n) time complexity.
 If the target number does not exist in the array, return -1.

 Example
 If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
 Challenge Expand 
 If the count of numbers is bigger than MAXINT, can your code work properly?
*/

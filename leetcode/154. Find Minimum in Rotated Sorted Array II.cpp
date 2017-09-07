/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Minimum in Rotated Sorted Array II
 Source:     https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/?tab=Description
 Tags:       {Array}, {Binary Search}

 Notes:
 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed? 
 Would this affect the run-time complexity? How and why?
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l<r){
            if(num[l] < num[r]) 
                return num[l];
            int m=(l+r)/2;
            if(num[m] > num[l])
                l = m+1;
            else if(num[m] < num[l])//既然num[m]小, 那么就有可能是那个最小的
                r = m;
            else{
                if(num[m] == num[r]){
                    l++; 
                    r--;
                }
                else
                    l=m+1;
            }
        }
        return num[l];
    }
};
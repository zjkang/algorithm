/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Remove Element
 Source:     https://leetcode.com/problems/remove-element/?tab=Description
 Tags:       {Array}, {Two Pointers}
 
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Example:
 Given input array nums = [3,2,2,3], val = 3

 Your function should return length = 2, with the first two elements of nums being 2.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int start = 0; // start: position that will be filled
        for (int i = 0; i < n; ++i) { // i: current position
            if (A[i] != elem) {
                A[start++] = A[i];        	            	
            }
        }    
        return start;
    }
};

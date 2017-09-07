/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    H-index
 Source:     https://leetcode.com/problems/h-index/?tab=Description
 Tags:       {Binary Search}
 Company:    Facebook

 Notes:
 Given an array of citations (each citation is a non-negative integer) of a researcher, 
 write a function to compute the researcher's h-index.

 According to the definition of h-index on Wikipedia: "A scientist has index h 
 if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

 For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total 
 and each of them had received 3, 0, 6, 1, 5 citations respectively. 
 Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, 
 his h-index is 3.

 Note: If there are several possible values for h, the maximum one is taken as the h-index.

 Hint:
 An easy approach is to sort the array first.
 What are the possible values of h-index?
 A faster approach is to use extra space.

 Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?
 Expected runtime complexity is in O(log n) and the input is sorted.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int start = 0, end = citations.size()-1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int h = citations.size() - mid;
            if (h <= citations[mid]) {
                if (mid == 0 || citations[mid-1] <= h) {
                    return h;
                } else {
                    end = mid;
                }
            } else {
                start = mid;
            }
        }
        
        int h = citations.size() - start;
        if (h <= citations[start] && (start == 0 || citations[start-1] <= h)) {
            return h;
        }
        h = citations.size() - end;
        if (h <= citations[end] && (end == 0 || citations[end-1] <= h)) {
            return h;
        }
        return 0;
    }
};

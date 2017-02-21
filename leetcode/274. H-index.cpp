/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    H-index
 Source:     https://leetcode.com/problems/h-index/?tab=Description
 Tags:       {Hash Table}, {Sort}
 Company:    Bloomberg, Google, Facebook

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
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        sort(citations.begin(), citations.end());
        for (int i = 0; i < citations.size(); ++i) {
            // [0,1,3,5,6]
            int h = citations.size() - i; // h-index
            if (h <= citations[i]) { // h-index condition-i
                if (i == 0 || citations[i-1] <= h) { // condition-ii
                    return h;
                }
            }
        }
        return 0;
    }
};



/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Find Right Interval
 Source:     https://leetcode.com/problems/find-right-interval/?tab=Description
 Difficulty: Medium
 Tags:       {Binary Search}
 
 Notes:
 Given a set of intervals, for each of the interval i, check if there exists an interval j whose start point is bigger than or equal to the end point of the interval i, which can be called that j is on the "right" of i.

 For any interval i, you need to store the minimum interval j's index, which means that the interval j has the minimum start point to build the "right" relationship for interval i. If the interval j doesn't exist, store -1 for the interval i. Finally, you need output the stored value of each interval as an array.

 Note:
 You may assume the interval's end point is always bigger than its start point.
 You may assume none of these intervals have the same start point.
 Example 1:
 Input: [ [1,2] ]

 Output: [-1]

 Explanation: There is only one interval in the collection, so it outputs -1.
 Example 2:
 Input: [ [3,4], [2,3], [1,2] ]

 Output: [-1, 0, 1]

 Explanation: There is no satisfied "right" interval for [3,4].
 For [2,3], the interval [3,4] has minimum-"right" start point;
 For [1,2], the interval [2,3] has minimum-"right" start point.
 Example 3:
 Input: [ [1,4], [2,3], [3,4] ]

 Output: [-1, 2, -1]

 Explanation: There is no satisfied "right" interval for [1,4] and [3,4].
 For [2,3], the interval [3,4] has minimum-"right" start point.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static int compare(const pair<Interval, int>& l, const pair<Interval, int>& r) {
        return l.first.start < r.first.start;
    }
    vector<int> findRightInterval(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        vector<int> res(intervals.size(), 0);
        vector<pair<Interval, int>> values;
        for (int i = 0; i < intervals.size(); ++i) {
            values.push_back({intervals[i], i});
        }
        sort(values.begin(), values.end(), compare);
        for (int i = 0; i < values.size(); ++i) {
            int start = i+1, end = values.size()-1;
            while (start + 1 < end) {
                int mid = start + (end - start) / 2;
                if (values[mid].first.start >= values[i].first.end) {
                    end = mid;
                } else {
                    start = mid;
                }
            }
            if (start < values.size() && values[start].first.start >= values[i].first.end) {
                res[values[i].second] = values[start].second;
            } else if (end < values.size() && values[end].first.start >= values[i].first.end) {
                res[values[i].second] = values[end].second;
            } else {
                res[values[i].second] = -1;
            }
        }
        return res;
    }
};
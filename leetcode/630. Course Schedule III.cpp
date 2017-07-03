/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Course Schedule III
 Source:     https://leetcode.com/problems/course-schedule-iii/#/description
 Difficulty: Medium
 Company:    WAP
 Tags:       {Greedy}

 Notes:
 There are n different online courses numbered from 1 to n. Each course has some duration(course length) t and closed on dth day. A course should be taken continuously for t days and must be finished before or on the dth day. You will start at the 1st day.

 Given n online courses represented by pairs (t,d), your task is to find the maximal number of courses that can be taken.

 Example:
 Input: [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
 Output: 3
 Explanation: 
 There're totally 4 courses, but you can take 3 courses at most:
 First, take the 1st course, it costs 100 days so you will finish it on the 100th day, and ready to take the next course on the 101st day.
 Second, take the 3rd course, it costs 1000 days so you will finish it on the 1100th day, and ready to take the next course on the 1101st day. 
 Third, take the 2nd course, it costs 200 days so you will finish it on the 1300th day. 
 The 4th course cannot be taken now, since you will finish it on the 3300th day, which exceeds the closed date.
 Note:
 The integer 1 <= d, t, n <= 10,000.
 You can't take two courses simultaneously.
*/

class Solution {
public:
    // refer to solution https://leetcode.com/problems/course-schedule-iii/#/solutions
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        if (courses.empty()) return 0;
        // sort based on the order of {course end} 
        sort(courses.begin(), courses.end(), compare);
        int curSum = 0;
        priority_queue<int, vector<int>, less<int>> q;
        
        for (int i = 0; i < courses.size(); ++i) {
            // greedy method, add courses in
            if (curSum + courses[i][0] <= courses[i][1]) {
                q.push(courses[i][0]);
                curSum += courses[i][0];
            } else if (q.top() > courses[i][0]) { 
                // remove current max duration and replace a smaller one 
                int val = q.top();
                q.pop();
                q.push(courses[i][0]);
                curSum += courses[i][0] - val; 
            }
        }
        return q.size();
    }
};
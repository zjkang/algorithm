/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Squirrel Simulation
 Source:     https://leetcode.com/problems/squirrel-simulation/#/description
 Difficulty: Medium
 Company:    Square
 Tags:       {Math}

 Notes:
 There's a tree, a squirrel, and several nuts. Positions are represented by the cells in a 2D grid. Your goal is to find the minimal distance for the squirrel to collect all the nuts and put them under the tree one by one. The squirrel can only take at most one nut at one time and can move in four directions - up, down, left and right, to the adjacent cell. The distance is represented by the number of moves.

 Example 1:
 Input: 
 Height : 5
 Width : 7
 Tree position : [2,2]
 Squirrel : [4,4]
 Nuts : [[3,0], [2,5]]
 Output: 12
 Explanation:
 
 Note:
 All given positions won't overlap.
 The squirrel can take at most one nut at one time.
 The given positions of nuts have no order.
 Height and width are positive integers. 3 <= height * width <= 10,000.
 The given positions contain at least one nut, only one tree and one squirrel.
 */

class Solution {
public:
    int distance(const vector<int>& a, const vector<int>& b) {
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }
    
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int res = INT_MAX, index = 0;
        int total = 0;
        for (int i = 0; i < nuts.size(); ++i) {
            int d = distance(tree, nuts[i]);
            int v = distance(squirrel, nuts[i]);
            total += d;
            if ((v-d) < res) {
                res = v-d; index = i;
            }
        }
        return 2*total + distance(squirrel, nuts[index]) - distance(tree, nuts[index]);
    }
};


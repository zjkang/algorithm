/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    The Maze
 Source:     https://leetcode.com/problems/the-maze/
 Difficulty: Medium
 Tags:       {Depth-first Search}, {Breadth-first Search}
 Company:    {Google}

 Notes:
 There is a ball in a maze with empty spaces and walls. 
 The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. 
 When the ball stops, it could choose the next direction.

 Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.

 The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. 
 You may assume that the borders of the maze are all walls. 
 The start and destination coordinates are represented by row and column indexes.

 Example 1

 Input 1: a maze represented by a 2D array

 0 0 1 0 0
 0 0 0 0 0
 0 0 0 1 0
 1 1 0 1 1
 0 0 0 0 0

 Input 2: start coordinate (rowStart, colStart) = (0, 4)
 Input 3: destination coordinate (rowDest, colDest) = (4, 4)

 Output: true
 Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.

 Example 2

 Input 1: a maze represented by a 2D array

 0 0 1 0 0
 0 0 0 0 0
 0 0 0 1 0
 1 1 0 1 1
 0 0 0 0 0

 Input 2: start coordinate (rowStart, colStart) = (0, 4)
 Input 3: destination coordinate (rowDest, colDest) = (3, 2)

 Output: false
 Explanation: There is no way for the ball to stop at the destination.

 Note:
 There is only one ball and one destination in the maze.
 Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
 The given maze does not contain border (like the red rectangle in the example pictures), 
 but you could assume the border of the maze are all walls.
 The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
*/

class Solution {
public:
    // direction: {up, right, down, left}
    vector<vector<int>> offset = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    vector<int> getPosOfHitWall(vector<vector<int>>& maze, vector<int>& start, int dir) {
        int rows = maze.size(), cols = maze[0].size();
        vector<int> p = start;
        vector<int> next = {p[0] + offset[dir][0], p[1] + offset[dir][1]};
        
        while (next[0] >= 0 && next[0] < rows && next[1] >= 0 && 
               next[1] < cols && maze[next[0]][next[1]] == 0) {
            p = next;
            next = {p[0] + offset[dir][0], p[1] + offset[dir][1]};
        }
        return p;
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<bool>>& visited) {
        visited[start[0]][start[1]] = true;
        vector<int> curr = start;
        
        for (int i = 0;i < offset.size(); ++i) {
            auto next = getPosOfHitWall(maze, curr, i);
            if (next[0] == destination[0] && next[1] == destination[1]) {
                return true;
            } else if ((next[0] == curr[0] && next[1] == curr[1]) || visited[next[0]][next[1]] == true) {
                continue;
            } else {
                if (dfs(maze, next, destination, visited)) {
                    return true;
                }        
            }
         }

        return false;
    }
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int rows = maze.size(), cols = maze[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        return dfs(maze, start, destination, visited);
    }
};


/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Graph Valid Tree
 Source:     https://leetcode.com/problems/graph-valid-tree/#/description
 Difficulty: Medium
 Tags:       {Depth-first Search}, {Breadth-first Search}, {Graph}, {Union Find} 
 Company:    Google, Facebook, Zenefits
 
 Notes:
 Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
 write a function to check whether these edges make up a valid tree.

 For example:

 Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

 Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.

 Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and 
 thus will not appear together in edges.
*/

class Solution {
public:
    bool dfs(int v, int l, map<int, vector<int>>& m, vector<int>& visited) {
        if (visited[v]) return false;
        visited[v] = true;
        for (auto i : m[v]) {
            if (i == l) continue;
            if (!dfs(i, v, m, visited)) {
                return false;
            }
        }
        return true;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        map<int, vector<int>> m;
        for (int i = 0; i < edges.size(); ++i) {
            m[edges[i].first].push_back(edges[i].second);
            m[edges[i].second].push_back(edges[i].first);
        }
        vector<int> visited(n, 0);
        if (!dfs(0, -1, m, visited)) return false; // cycle graph
        for (int i = 1; i < n; ++i) { // non-connected graph
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};

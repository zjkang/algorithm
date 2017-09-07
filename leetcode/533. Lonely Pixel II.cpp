/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Lonely Pixel II
 Source:     https://leetcode.com/problems/lonely-pixel-ii/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Array, Depth-first Search}

 Notes:
 Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:

 Row R and column C both contain exactly N black pixels.
 For all rows that have a black pixel at column C, they should be exactly the same as row R
 The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

 Example:
 Input:                                            
 [['W', 'B', 'W', 'B', 'B', 'W'],    
  ['W', 'B', 'W', 'B', 'B', 'W'],    
  ['W', 'B', 'W', 'B', 'B', 'W'],    
  ['W', 'W', 'B', 'W', 'B', 'W']] 

 N = 3
 Output: 6
 Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
         0    1    2    3    4    5         column index                                            
 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
 row index

 Take 'B' at row R = 0 and column C = 1 as an example:
 Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
 Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.

 Note:
 The range of width and height of the input 2D array is [1,200].
*/

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        // Similar to Lonely Pixel I, add hash to store row/col picture configuration.
        int r = picture.size(), c = picture[0].size();
        vector<int> rows(r, 0);
        vector<int> cols(c, 0);
        unordered_map<string,int> hash;
        vector<string> config;
        for (int i = 0; i < r; ++i) {
            string s;
            for (int j = 0; j < c; ++j) {
                if (picture[i][j] == 'B') {
                    rows[i]++; cols[j]++;
                }
                s.push_back(picture[i][j]);
            }
            config.push_back(s);
            hash[s]++;
        }
        
        int res = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (rows[i] == N && cols[j] == N && hash[config[i]] == N && picture[i][j] == 'B') {
                    res++;
                }
            }
        }
        return res;
    }
};


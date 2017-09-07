/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Lonely Pixel I
 Source:     https://leetcode.com/problems/lonely-pixel-i/#/description
 Difficulty: Medium
 Company:    Google
 Tags:       {Array, Depth-first Search}

 Notes:
 Given a picture consisting of black and white pixels, find the number of black lonely pixels.

 The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

 A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.

 Example:
 Input: 
 [['W', 'W', 'B'],
  ['W', 'B', 'W'],
  ['B', 'W', 'W']]

 Output: 3
 Explanation: All the three 'B's are black lonely pixels.
 Note:
 The range of width and height of the input 2D array is [1,500].
*/

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        // Use hash to store how many pixels in the specific row or col, and
        // the pixel satisfying the requirement should have 
        // picture[i][j] = 'B' && row[i] = 1 && cols[j] = 1
        int res = 0;
        int r = picture.size(), c = picture[0].size();
        vector<int> row(r, 0);
        vector<int> col(c, 0);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (picture[i][j] == 'B') {
                    row[i]++; col[j]++;
                }
            }
        }
        
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};

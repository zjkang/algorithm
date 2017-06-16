/*
 Author:     Zhengjian Kang
 Email:      zhengjian.kang@nyu.edu
 Problem:    Predict the Winner
 Source:     https://leetcode.com/problems/predict-the-winner/#/description
 Difficulty: Medium
 Tags:       {Dynamic Programming}, {Minimax}
 Company:    Google

 Notes:
 Given an array of scores that are non-negative integers. 
 Player 1 picks one of the numbers from either end of the array followed by the player 2 and 
 then player 1 and so on. Each time a player picks a number, 
 that number will not be available for the next player. This continues until all the scores have been chosen. 
 The player with the maximum score wins.

 Given an array of scores, predict whether player 1 is the winner. 
 You can assume each player plays to maximize his score.

 Example 1:
 Input: [1, 5, 2]
 Output: False
 Explanation: Initially, player 1 can choose between 1 and 2. 
 If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. 
 If player 2 chooses 5, then player 1 will be left with 1 (or 2). 
 So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
 Hence, player 1 will never be the winner and you need to return False.
 
 Example 2:
 Input: [1, 5, 233, 7]
 Output: True
 Explanation: Player 1 first chooses 1. Then player 2 have to choose between 5 and 7. 
 No matter which number player 2 choose, player 1 can choose 233.
 Finally, player 1 has more score (234) than player 2 (12), 
 so you need to return True representing player1 can win.
 Note:
 1 <= length of the array <= 20.
 Any scores in the given array are non-negative integers and will not exceed 10,000,000.
 If the scores of both players are equal, then player 1 is still the winner.
*/

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] = sum[i-1] + nums[i];
        }
        
        // max possible value between [i,j]
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][i] = nums[i];
        }
        
        for (int len = 1; len < nums.size(); len++) {
            for (int i = 0 ; i < nums.size() && i + len < nums.size(); ++i) {
                int j = i + len;
                int num1 = nums[i] + sum[j] - sum[i] - dp[i+1][j];
                int num2 = nums[j] + sum[j-1] - (i-1 >= 0 ? sum[i-1] : 0) - dp[i][j-1];
                dp[i][j] = max(num1, num2);
            }
        }
        
        // cout << dp[0][nums.size()-1] << endl;
        return dp[0][nums.size()-1] >= (sum[nums.size()-1] - dp[0][nums.size()-1]);
    }
};


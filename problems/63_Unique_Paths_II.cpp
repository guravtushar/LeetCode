/*
https://leetcode.com/problems/unique-paths-ii/
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                    dp[i][j]=1;
                }
                else if(i==0){
                    dp[i][j]=obstacleGrid[i][j-1]?0:dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j]=obstacleGrid[i-1][j]?0:dp[i-1][j];
                }
                else{
                    int up=obstacleGrid[i-1][j];
                    int left=obstacleGrid[i][j-1];
                    dp[i][j]=(up?0:dp[i-1][j])+(left?0:dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};

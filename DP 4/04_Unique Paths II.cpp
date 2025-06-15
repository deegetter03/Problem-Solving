#include <bits/stdc++.h>
using namespace std;
//lc63

//METHOD 1
class Solution {
public:
    int pathways(int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {

        if (i == 0 && j == 0 && obstacleGrid[i][j] == 0) //target place
            return 1;

        if (i < 0 || j < 0) // boundary ke bahar
            return 0;

        if (obstacleGrid[i][j] == 1) // obstacle
            return 0;

        if (dp[i][j] != -1) // value taken
            return dp[i][j];

        int up = pathways(i - 1, j, obstacleGrid, dp);   // Moving up
        int left = pathways(i, j - 1, obstacleGrid, dp); // Moving left

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return pathways(m - 1, n - 1, obstacleGrid, dp);
    }
};

//METHOD 2 
class Solution {
  public:      
      int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
          int m = obstacleGrid.size();
          int n = obstacleGrid[0].size();
          
          vector<vector<int>> dp(m,vector<int> (n,0));
          
          for(int i=0;i<m;i++)
          {
              for(int j=0;j<n;j++)
              {
                  if(i==0 && j==0 && obstacleGrid[i][j]==0)
                      dp[i][j]=1;
                  
                  else if(obstacleGrid[i][j]==1)
                      dp[i][j] = 0;
                  
                  else
                  {
                      int left = 0,up=0;
					  
                      if(i>0) up = dp[i-1][j];
                      if(j>0) left = dp[i][j-1];
                      
                      dp[i][j] = up + left;
                  }
              }
          }                                
          return dp[m-1][n-1];
      }
  };
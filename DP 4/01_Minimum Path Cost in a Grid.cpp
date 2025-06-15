#include <bits/stdc++.h>
using namespace std;
//lc2304

class Solution {
public:
    int ways(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>& dp) {
        if (i == grid.size() - 1) {
            return grid[i][j];
        }
        if (dp[i][j] != -1) return dp[i][j];

        int cost = INT_MAX;
        for (int k = 0; k < grid[0].size(); k++) {
            int current = grid[i][j];
            cost = min(cost, grid[i][j] + moveCost[current][k] + ways(i + 1, k, grid, moveCost, dp));
        }
        return dp[i][j] = cost;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();

        int result = INT_MAX;
        vector<vector<int>> dp(m * n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i < m; i++) {
            result = min(result, ways(0, i, grid, moveCost, dp));
        }
        return result;
    }
};
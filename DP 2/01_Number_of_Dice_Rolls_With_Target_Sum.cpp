#include <bits/stdc++.h>
using namespace std;

//lc1155
//METHOD 1
class Solution {
public:
    int mod = 1e9 + 7;
    long solve(int i, int k, int target, int sum, vector<vector<int>>& dp) {
        if (i < 1 && sum == target) {
            return 1;
        }
        if (i < 1)
            return 0;
        if (dp[i][sum] != -1)
            return dp[i][sum];
        long temp = 0;
        for (int j = 1; j <= k; j++) {
            temp += solve(i - 1, k, target, sum + j, dp);
        }
        return dp[i][sum] = temp % mod;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(1001, -1));
        return solve(n, k, target, 0, dp);
    }
};

//METHOD 2
class Solution {
public:
    const long long mod = 1e9 + 7;
    vector<vector<int>> dp = vector<vector<int>>(31, vector<int>(1001, -1));
    int solve(int ind, vector<vector<int>>& grid, int k, int target) {
        if (target < 0) {
            return 0;
        }
        if (ind < 0) {
            return target == 0;
        }
        if (target == 0) {
            return 0;
        }

        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans = (ans + solve(ind - 1, grid, k, target - grid[ind][i])) % mod;
        }
        return dp[ind][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < k; j++) {
                temp.push_back(j + 1);
            }
            grid.push_back(temp);
        }
        return solve(n - 1, grid, k, target) % mod;
    }
};
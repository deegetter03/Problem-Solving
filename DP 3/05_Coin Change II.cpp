#include <bits/stdc++.h>
using namespace std;
//lc518

//METHOD 1
class Solution {
public:
    int ways(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (!i) {
            if (amount % coins[0] == 0)
                return 1;
            return 0;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];
        int notpick = ways(i - 1, amount, coins, dp);
        int pick = 0;
        if (amount >= coins[i])
            pick = ways(i, amount - coins[i], coins, dp);
        return dp[i][amount] = pick + notpick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return ways(n - 1, amount, coins, dp);
    }
};

//METHOD 2
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                dp[0][j] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notpick = dp[i - 1][j];
                int pick = 0;
                if (j >= coins[i])
                    pick = dp[i][j - coins[i]];
                dp[i][j] = pick + notpick;
            }
        }
        return dp[n - 1][amount];
    }
};

//METHod 3
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> previous(amount + 1, 0), current(amount + 1, 0);
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                previous[j] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notpick = previous[j];
                int pick = 0;
                if (j >= coins[i])
                    pick = current[j - coins[i]];
                current[j] = pick + notpick;
            }
            previous = current;
        }
        return previous[amount];
    }
};
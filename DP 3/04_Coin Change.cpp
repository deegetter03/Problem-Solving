#include <bits/stdc++.h>
using namespace std;
//lc322

//METHOD 1
class Solution {
public:
    int ways(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (!i) {
            if (amount % coins[i] == 0)
                return amount / coins[i];
            else
                return 1e9;
        }

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int notpick = ways(i - 1, amount, coins, dp);
        int pick = 1e9;
        if (amount >= coins[i])
            pick = 1 + ways(i, amount - coins[i], coins, dp);
        return dp[i][amount] = min(pick, notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector(amount + 1, -1));
        int ans = ways(n - 1, amount, coins, dp);
        if (ans != 1e9)
            return ans;
        return -1;
    }
};

//METHOD 2
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> previous(amount + 1, 0), current(amount + 1, 0);
        for (int j = 0; j <= amount; j++) {
            if (j % coins[0] == 0)
                previous[j] = j / coins[0];
            else
                previous[j] = 1e9;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= amount; j++) {
                int notpick = previous[j];
                int pick = 1e9;
                if (j >= coins[i])
                    pick = 1 + current[j - coins[i]];
                current[j] = min(pick, notpick);
            }
            previous = current;
        }
        if (previous[amount] != 1e9)
            return previous[amount];
        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;
//lc62

//METHOD 1
class Solution {
    public:
        unordered_map<int, unordered_map<int, int> > hash;
        int uniquePaths(int m, int n) {
            if(m == 0 || n == 0)
                return 0;
            if(m == 1 || n == 1)
                return 1;
            if(hash.find(m) != hash.end() && hash[m].find(n) != hash[m].end())
                return hash[m][n];
            return hash[m][n] = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        }
};

//METHOD 2 
class Solution {
public:
    int ways(int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return 1;
        if (i == -1 || j == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j]; // memeoziation

        int down = ways(i - 1, j, dp);
        int right = ways(i, j - 1, dp);

        dp[i][j] = down + right;

        return down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int answer = ways(m - 1, n - 1, dp);
        return answer;
    }
};

//METHOD 3
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++) {
                if (i + j == 0)
                    temp[j] = 1;
                else {
                    int down = 0, right = 0;
                    if (j > 0)
                        right = temp[j - 1];
                    down = dp[j];

                    temp[j] = right + down;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};
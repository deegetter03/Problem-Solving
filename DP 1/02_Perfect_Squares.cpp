#include <bits/stdc++.h>
using namespace std;

//lc279
//METHOD 1 
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i=0;i<n+1;i++)dp[i] = 1e9;
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i] = min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};

//METHOD 2
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int count = INT_MAX;
            for (int num = 1; num <= sqrt(n); num++) {
                if (i - (num * num) >= 0)
                    count = min(count, 1 + dp[i - (num * num)]);
            }
            dp[i] = count;
        }
        return dp[n];
    }
};
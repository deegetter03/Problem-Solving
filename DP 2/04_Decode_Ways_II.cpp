#include <bits/stdc++.h>
using namespace std;

//lc639

class Solution {
public:
    int mod = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.length();
        if (s[0] == '0') return 0;

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : 1;

        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '*') {
                dp[i] = (dp[i] + dp[i - 1] * 9) % mod;
            } 

            else {
                if (s[i - 1] != '0'){
                    dp[i] = (dp[i] + dp[i - 1]) % mod;
                } 
            }

            if (s[i - 1] == '*' && s[i - 2] == '*') {
                dp[i] = (dp[i] + dp[i - 2] * 15) % mod;
            } 
            else if (s[i - 1] != '*' && s[i - 2] != '*') {
                int k = stoi(s.substr(i - 2, 2));
                if (k <= 26 && k > 0 && s[i - 2] != '0'){
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
                }      
            } 
            else if (s[i - 1] == '*') {
                if (s[i - 2] == '1'){
                    dp[i] = (dp[i] + dp[i - 2] * 9) % mod;
                }
                if (s[i - 2] == '2'){
                    dp[i] = (dp[i] + dp[i - 2] * 6) % mod;
                }   
            } 
            else if (s[i - 2] == '*') {
                if (s[i - 1] <= '6')
                    dp[i] = (dp[i] + dp[i - 2] * 2) % mod;
                else
                    dp[i] = (dp[i] + dp[i - 2]) % mod;
            }
        }
        return dp[n] % mod;
    }
};
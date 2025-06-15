#include <bits/stdc++.h>
using namespace std;

//lc91
//METHOD 1
class Solution {
public:
    int dp[109][109];
    int solve(int i, int j, string& s) {
        if (i == s.size())
            return 1;
        int& ans = dp[i][j];
        if (~ans)
            return ans;
        ans = 0;
        if (s[i] - '0')
            ans += solve(i + 1, s[i] - '0', s);
        if (j && j * 10 + (s[i] - '0') < 27)
            ans += solve(i + 1, j * 10 + (s[i] - '0'), s);

        return ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, s);
    }
};

//METHOD 2
class Solution {
public:
    int numDecodings(string s) {
        vector<int> d(s.size() + 1, 0);
        string t = s.substr(0, 2);
        d[0] = (s[0] == '0' ? 0 : 1),
        d[1] = (t[1] != '0' ? d[0] : 0) + (stoi(t) <= 26 && t[0] != '0' ? 1 : 0);
        for (int i = 2; i < s.size(); i++) {
            t = s.substr(i - 1, 2);
            d[i] = (t[1] != '0' ? d[i - 1] : 0) + (stoi(t) <= 26 && t[0] != '0' ? d[i - 2] : 0);
        }
        return d[s.size() - 1];
    }
};

//METHOD 3
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        if (s.size() == 0 || s[0] == '0') return 0;

        dp[0] = 1;
        dp[1] = 1;
        int n = s.size();
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] >= '1' && s[i - 1] <= '9'){
                dp[i] = dp[i - 1];
            }
            if (s[i - 2] == '1'){
                dp[i] += dp[i - 2];
            }
            else if (s[i - 2] == '2' && (s[i - 1] >= '0' && s[i - 1] <= '6')){
                dp[i] += dp[i - 2];
            }    
        }
        return dp[n];
    }
};
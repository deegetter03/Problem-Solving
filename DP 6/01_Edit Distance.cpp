#include <bits/stdc++.h>
using namespace std;

//lc72
//METHOD 1
class Solution {
public:
    int count(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
        if (j < 0) return i + 1;
        if (i < 0) return j + 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            return dp[i][j] = count(word1, word2, i - 1, j - 1, dp);
        } 
        else {
            // insert
            int insert = 1 + count(word1, word2, i, j - 1, dp);
            // delete
            int del = 1 + count(word1, word2, i - 1, j, dp);
            // replace
            int replace = 1 + count(word1, word2, i - 1, j - 1, dp);
            // return mini
            return dp[i][j] = min(insert, min(del, replace));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return count(word1, word2, n - 1, m - 1, dp);
    }
};

//METHOD 2
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for(int i=0; i<=n; i++) dp[i][0] = i;
        for(int j=0; j<=m; j++) dp[0][j] = j;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i - 1] == t[j - 1]) {
                    // If the characters match, no additional cost
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
        return dp[n][m];
    }
};

//METHOD 3
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> previous(m + 1, 0);
        vector<int> current(m + 1, 0);
        for (int j = 0; j <= m; j++)
            previous[j] = j;
        for (int index1 = 1; index1 <= n; index1++) {
            current[0] = index1;
            for (int index2 = 1; index2 <= m; index2++) {
                if (s[index1 - 1] == t[index2 - 1])
                    current[index2] = previous[index2 - 1];
                else {
                    int insertions = 1 + current[index2 - 1];
                    int deletions = 1 + previous[index2];
                    int replacements = 1 + previous[index2 - 1];
                    current[index2] = min(insertions, min(deletions, replacements));
                }
            }
            previous = current;
        }
        return previous[m];
    }
};
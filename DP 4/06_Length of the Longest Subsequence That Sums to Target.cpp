#include <bits/stdc++.h>
using namespace std;
//lc2915

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> dp(size + 1, vector<int>(target + 1, -1));
        for (int i = 0; i <= size; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= target; j++) {
                if (j - nums[i - 1] >= 0 && dp[i - 1][j - nums[i - 1]] != -1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + 1);
                } 
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[size][target];
    }
};
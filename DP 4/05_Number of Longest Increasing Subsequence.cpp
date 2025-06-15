#include <bits/stdc++.h>
using namespace std;
//lc673

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int maxLength = 1;
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < (dp[j] + 1)) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] == (dp[j] + 1)) {
                        count[i] += count[j];
                    }
                }
                maxLength = max(maxLength, dp[i]);
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (dp[i] == maxLength)
                answer += count[i];
        }
        return answer;
    }
};
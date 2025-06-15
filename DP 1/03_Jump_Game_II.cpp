#include <bits/stdc++.h>
using namespace std;

//lc45
//METHOD 1
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int far = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            far = max(far, i + nums[i]);

            if (i == currentEnd) {
                ++jumps;
                currentEnd = far;
            }
        }
        return jumps;
    }
};

//METHOD 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int>dp(size,1e9);
        dp[size-1]= 0;
        
        for(int i= size-2;i>=0;i--){
            for(int j = i+1;j<=min(size-1,i+nums[i]);j++){
                dp[i]= min(dp[i],dp[j]+1);
            }
        }
        return dp[0];
    }
};
#include <bits/stdc++.h>
using namespace std;
//lc198

//METHOD 1 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> rob(n+1,0);
        rob[n] = 0;
        rob[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            rob[i] = max(nums[i] + rob[i+2], rob[i+1]);
        }
        return rob[0];
    }
};

//METHOD 2
class Solution {
public:
    int solve(vector<int>& v, int n, vector<int>& dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return v[n];
        if (dp[n] != -1)
            return dp[n];
        int take = v[n] + solve(v, n - 2, dp);
        int notTake = 0 + solve(v, n - 1, dp);
        return dp[n] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, n - 1, dp);
    }
};
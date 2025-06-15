#include <bits/stdc++.h>
using namespace std;

//lc213
//METHOD 1
class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            int include = dp[i - 2] + nums[i - 1];
            int exclude = dp[i - 1];
            dp[i] = max(include, exclude);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> first, second;
        if (n == 1) {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1) {
                first.push_back(nums[i]);
            }
            if (i != 0) {
                second.push_back(nums[i]);
            }
        }
        return max(solve(first), solve(second));
    }
};

//METHOD 2
class Solution {
public:
    int rob(vector<int>& nums) {
        int left  = robber(nums);
        reverse(nums.begin(),nums.end());
        int right = robber(nums);
        return max(left,right);
    }
    int robber(vector<int>&nums){
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        for(int i=1;i<nums.size()-1;i++){
            if(i-2 >= 0){
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }else{
                dp[i] = max(dp[i-1],nums[i]);
            }
        }
        int res = 0;
        for(auto i :dp){
            res=max(res,i);
        }
        return res;
    }
};
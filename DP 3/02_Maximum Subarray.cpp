#include <bits/stdc++.h>
using namespace std;
//lc53

//METHOD 1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            sum = sum + nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if( sum < 0){
                sum = 0;
            }
        }
        return maxi;
    }
};

//METHOD 2
class Solution {
public:
    // Kadane's Algorithm
    int maxSubArray(vector<int>& n) {
        int maxx = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n.size(); i++) {
            sum += n[i];
            maxx = max(maxx, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxx;
    }
};

//METHOD 3
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
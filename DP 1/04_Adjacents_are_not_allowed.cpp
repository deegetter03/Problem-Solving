#include <bits/stdc++.h>
using namespace std;

//METHOD 1
class Solution{
public:
    int maxSum(int n, vector<vector<int>> mat)
    {
        int dp[n];
        for(int i=0;i<n;i++) {
              dp[i]=max(mat[0][i],mat[1][i]);
         }
        int ans[n];
        ans[0]=dp[0];
        ans[1]=dp[1];
        ans[2]=dp[0]+dp[2];
        for(int i=3;i<n;i++)
        {
            ans[i]=max(ans[i-2],ans[i-3])+dp[i];
            ans[i]=max(ans[i-1],ans[i]);
        }
        return ans[n-1];
    }
};
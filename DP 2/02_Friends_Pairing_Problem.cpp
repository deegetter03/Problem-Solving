#include <bits/stdc++.h>
using namespace std;

//METHOD 1
#define ll long long
class Solution
{
public:
    int mod=1000000007;
    ll memoization(int i,vector<ll>& memo)
    {
        //base case
        if(i==1 or i==2)
        return i;
        
        //memo
        if(memo[i]!=-1)
        return memo[i];
            
        //recursive
        ll a=memoization(i-1,memo)%mod;
        ll b=((i-1)*(memoization(i-2,memo)%mod))%mod;
        
        return memo[i]=(a+b)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        vector<ll> memo(n+1,-1); 
        return memoization(n,memo);
    }
};

//METHOD 2
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int mod=1e9+7;
        long long int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+(i-1)*dp[i-2])%mod;
        }
        return dp[n];
    }
};  

//METHOD 3
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        if(n < 3) return n;
        long long prev2 = 1,prev1 = 2,ans,mod = 1e9+7;
        for(int i = 2;i < n;i++){
            ans = (prev1+(prev2*i))%mod;
            prev2 = prev1;
            prev1 = ans;
        }
        return ans;
    }
};   

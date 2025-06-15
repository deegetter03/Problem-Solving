#include <bits/stdc++.h>
using namespace std;
//lc70

//METHOD 1
class Solution {
public:
    int climbStairs(int n) {
        vector<int> steps(3, 0);
        steps[0] = 1;
        steps[1] = 1;
        for (int i = 2; i <= n; ++i) {
            steps[i % 3] = steps[(i - 1) % 3] + steps[(i - 2) % 3];
        }
        return steps[n % 3];
    }
};

//METHOD 2
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3)
            return n;
        int step1{1};
        int step2{2};
        int finalstep{0};
        while (n-- > 2) {
            finalstep = step1 + step2;
            step1 = step2;
            step2 = finalstep;
        }
        return finalstep;
    }
};

//METHOD 3
class Solution {
public:
    vector<int>dp;
    int n;
    int solve(int steps){
        if(steps > n) return 0;
        if(steps == n) return 1;
        if(dp[steps] != -1) return dp[steps];
        return dp[steps] = solve(steps+1) + solve(steps+2);
    }

    int climbStairs(int n) {
        dp.resize(n,-1);
        this->n = n;
        return solve(0);
    }
};
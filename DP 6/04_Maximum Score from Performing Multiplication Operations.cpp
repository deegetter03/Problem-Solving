#include <bits/stdc++.h>
using namespace std;
//lc1770
//tle

class Solution {
public:
    int n, m;
    //start or left or l , end or right or r
    int getit(int start, vector<int>& nums, int i, vector<int>& multi) {
        if (i == m) return 0;

        int end = (n - 1) - (i - start);
        return max(nums[start] * multi[i] + getit(start + 1, nums, i + 1, multi), nums[end] * multi[i] + getit(start, nums, i + 1, multi));
    }

    int maximumScore(vector<int>& nums, vector<int>& multi) {
        n = nums.size();
        m = multi.size();
        return getit(0, nums, 0, multi);
    }
};
#include <bits/stdc++.h>
using namespace std;

// lc300
// METHOD 1: bottom up

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int answer = 1;
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            int maxpreviouslis = 0;
            for (int j = 0; j <= i - 1; j++) {
                if (nums[i] > nums[j]) {
                    maxpreviouslis = max(maxpreviouslis, dp[j]);
                }
            }
            dp[i] = maxpreviouslis + 1;
            answer = max(answer, dp[i]); 
        }
        return answer;
    }
};

// METHOD 2: BS
class Solution
{
public:
    int findindex(vector<int> &lis, int num)
    {
        int n = lis.size();
        int low = 0;
        int high = n - 1;
        int ans = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (lis[mid] == num)
            {
                return mid;
            }
            if (lis[mid] > num)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lisstorage;
        lisstorage.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > lisstorage[lisstorage.size() - 1])
            {
                lisstorage.push_back(nums[i]);
            }
            else
            {
                int idx = findindex(lisstorage, nums[i]);
                lisstorage[idx] = nums[i];
            }
        }
        return lisstorage.size();
    }
};
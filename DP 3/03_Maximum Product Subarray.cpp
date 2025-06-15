#include <bits/stdc++.h>
using namespace std;
//lc152
//METHOD 1
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; i++) {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n - i - 1];
            ans = max(ans, max(prefix, suffix));
        }
        return ans;
    }
};

//METHOD 2
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int maxx = nums[0];
        int mini = nums[0];
        int result = maxx;
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(maxx, mini);
            }

            maxx = max(nums[i], maxx * nums[i]);
            mini = min(nums[i], mini * nums[i]);
            result = max(result, maxx);
        }
        return result;
    }
};
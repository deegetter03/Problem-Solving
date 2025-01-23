#include <bits/stdc++.h>
using namespace std;

//lc862
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        {
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + nums[i];
            }
            deque<int> dq;
            int mini = n + 1;
            for (int i = 0; i <= n; i++) {
                while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                    mini = min(mini, i - dq.front());
                    dq.pop_front();
                }
                while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            return mini == n + 1 ? -1 : mini;
        }
    }
};
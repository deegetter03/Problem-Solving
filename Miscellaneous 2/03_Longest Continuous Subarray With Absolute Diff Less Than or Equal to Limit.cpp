#include <bits/stdc++.h>
using namespace std;

//lc1438
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i = 0, j = 0;
        queue<int> qu;
        multiset<int> st;
        int count = 0;

        while (j < nums.size()) {
            qu.push(nums[j]);
            st.insert(nums[j]);
            int maxx = *st.rbegin();
            int mini = *st.begin();

            if (maxx - mini > limit) {
                while (qu.size() != 0) {
                    int z = qu.front();
                    if (z == maxx || z == mini) {
                        st.erase(st.find(z));
                        qu.pop();
                        i++;
                        break;
                    } 
                    else {
                        st.erase(st.find(z));
                        qu.pop();
                        i++;
                    }
                }
            }
            count = max(j - i + 1, count);
            j++;
        }
        return count;
    }
};
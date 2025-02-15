#include <bits/stdc++.h>
using namespace std;

//lc1944
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& nums) {
        vector<int> answer(nums.size());
        answer[nums.size() - 1] = 0;
        stack<int> st;
        st.push(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; i--) {
            int count = 0;
            while (!st.empty() && nums[i] > st.top()) {
                count++;
                st.pop();
            }
            if (!st.empty())
                count++;
            st.push(nums[i]);
            answer[i] = count;
        }
        return answer;
    }
};
#include <bits/stdc++.h>
using namespace std;

//lc904
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0;
        unordered_map<int, int> m;
        int ans = 0;

        while (right < n) {
            m[fruits[right]]++;

            while (m.size() > 2) {
                m[fruits[left]]--;
                if (m[fruits[left]] == 0)
                    m.erase(fruits[left]);
                left++;
            }
            if (m.size() <= 2)
                ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
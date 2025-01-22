#include <bits/stdc++.h>
using namespace std;

//lc475,bs
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0; i < houses.size(); i++) {
            int start = 0, end = heaters.size() - 1, current_radius = INT_MAX;
            while (start <= end) {
                int mid = start + (end - start) / 2;
                if (houses[i] == heaters[mid]) {
                    current_radius = 0;
                    break;
                } 
                else {
                    int diff = abs(houses[i] - heaters[mid]);
                    current_radius = min(diff, current_radius);
                    if (houses[i] > heaters[mid]) {
                        start = mid + 1;
                    } 
                    else if (houses[i] < heaters[mid]) {
                        end = mid - 1;
                    }
                }
            }
            ans = max(ans, current_radius);
        }
        return ans;
    }
};
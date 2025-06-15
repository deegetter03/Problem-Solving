#include <bits/stdc++.h>
using namespace std;

//lc2140
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        if(questions.empty()) return 0;
        int n = questions.size();
        vector<long> points(n, 0);

        points[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--) {
            long solve = questions[i][0] + (i + questions[i][1] + 1 < n ? points[i + questions[i][1] + 1] : 0);
            long skip = points[i + 1];
            points[i] = max(solve, skip);
        }
        return points.front();
    }
};
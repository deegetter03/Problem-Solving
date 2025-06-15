#include <bits/stdc++.h>
using namespace std;
//lc64

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> previous(m, 0);

        for (int i = 0; i < n; i++) {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) temp[j] = grid[i][j];
                else {
                    int upar = grid[i][j];
                    if (i > 0) upar += previous[j];
                    else upar += 1e9;

                    int left = grid[i][j];
                    if (j > 0) left += temp[j - 1];
                    else left += 1e9;

                    temp[j] = min(upar, left);
                }
            }
            previous = temp;
        }
        return previous[m - 1];
    }
};
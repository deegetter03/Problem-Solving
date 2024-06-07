#include <bits/stdc++.h>
using namespace std;

// lc1391
class Solution
{
public:
    map<int, set<pair<int, int>>> mpp;
    int n, mm;
    bool dfs(vector<vector<int>> &v, int r, int c, vector<vector<int>> &vis)
    {
        vis[r][c] = 1;
        if (r == n - 1 && c == mm - 1)
            return true;
        // vector<int> temp=m[v[r][c]];
        for (auto i : mpp[v[r][c]])
        {
            int nr = r + i.first;
            int nc = c + i.second;
            if (nr >= 0 && nc >= 0 && nr < n && nc < mm && vis[nr][nc] == 0 && mpp[v[nr][nc]].find({-1 * i.first, -1 * i.second}) != mpp[v[nr][nc]].end())
            {
                /* in this checking if current node has right than its child
                 * must have left and so on */
                if (dfs(v, nr, nc, vis))
                    return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        mpp[1] = {{0, -1}, {0, 1}};
        mpp[2] = {{-1, 0}, {1, 0}};
        mpp[3] = {{0, -1}, {1, 0}};
        mpp[4] = {{0, 1}, {1, 0}};
        mpp[5] = {{0, -1}, {-1, 0}};
        mpp[6] = {{0, 1}, {-1, 0}};
        n = grid.size();
        mm = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(mm, 0));
        return dfs(grid, 0, 0, vis);
    }
};
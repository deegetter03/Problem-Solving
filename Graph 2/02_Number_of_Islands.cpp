#include <bits/stdc++.h>
using namespace std;

// lc200
class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        grid[i][j] = '2';
        int d[] = {-1, 0, 1, 0};
        int e[] = {0, -1, 0, 1};
        for (int k = 0; k < 4; k++)
        {
            int newr = i + d[k];
            int newc = j + e[k];
            if (newr >= 0 && newc >= 0 && newr < n && newc < m &&
                grid[newr][newc] == '1')
            {
                dfs(grid, newr, newc, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int k = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, n, m);
                    k++;
                }
            }
        }
        return k;
    }
};
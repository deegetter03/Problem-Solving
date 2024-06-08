#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> ans(r, vector<int>(c, INT_MAX));

        queue<pair<int, int>> q;

        // Enqueue all 1s and mark their distance as 0.
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Define the four directions: up, down, left, right.
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Perform BFS.
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            // Explore neighbors.
            for (auto &dir : directions)
            {
                int dx = dir.first;
                int dy = dir.second;
                int nx = x + dx;
                int ny = y + dy;
                // Check if the neighbor is within bounds and its distance can be updated.
                if (nx >= 0 && nx < r && ny >= 0 && ny < c && ans[nx][ny] == INT_MAX)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }
};
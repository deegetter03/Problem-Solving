#include <bits/stdc++.h>
using namespace std;

// lc994
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int minutes = 0, freshOranges = 0;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> rotten;

        // Count fresh oranges and push rotten oranges to the queue
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    rotten.push({i, j});
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        // If there are no fresh oranges initially, return 0
        if (freshOranges == 0)
            return 0;

        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (!rotten.empty())
        {
            int size = rotten.size();
            bool changed = false;

            for (int i = 0; i < size; i++)
            {
                pair<int, int> curr = rotten.front();
                rotten.pop();

                for (auto dir : directions)
                {
                    int newX = curr.first + dir[0];
                    int newY = curr.second + dir[1];

                    if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                        grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        rotten.push({newX, newY});
                        freshOranges--;
                        changed = true;
                    }
                }
            }
            if (changed)
                minutes++;
        }
        return freshOranges == 0 ? minutes : -1;
    }
};
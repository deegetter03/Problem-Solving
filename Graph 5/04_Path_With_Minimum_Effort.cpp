#include <bits/stdc++.h>
using namespace std;

//lc1631
class Solution {
public:
#define ppi pair<int, pair<int, int>>
    vector<vector<int>> dir = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // directions to move
    int minimumEffortPath(vector<vector<int>>& grid) {

        priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
        vector<vector<int>> dis(grid.size(),
                                vector<int>(grid[0].size(), INT_MAX));
        pq.push({0, {0, 0}});
        dis[0][0] = 0;

        while (!pq.empty()) {
            auto k = pq.top();
            pq.pop();
            int x = k.second.first;  // curr x
            int y = k.second.second; // curr y
            int d = k.first;         // curr max dis

            if (x == grid.size() - 1 and y == grid[0].size() - 1)
                return dis[x][y];
            for (auto it : dir) {
                int x1 = x + it[0];
                int y1 = y + it[1];

                if (x1 >= 0 and y1 >= 0 and x1 < grid.size() and
                    y1 < grid[0].size()) {
                    int dis1 =
                        abs(grid[x][y] -
                            grid[x1][y1]);     // effort in going to next cell
                    int newmax = max(dis1, d); // new maximum effort
                    if (newmax < dis[x1][y1])  // if new maxeffort less upadate
                                               // in distance array
                    {
                        dis[x1][y1] = newmax;
                        pq.push({newmax, {x1, y1}});
                    }
                }
            }
        }
        return -1;
    }
};
#include <bits/stdc++.h>
using namespace std;
//lc2608

class Solution {
public:
    vector<int> g[1005];
    vector<int> dis;
    int n;
    int ans;

    void bfs(int st) {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            dis[i] = 1e9;
        }
        q.push(st);
        dis[st] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto v : g[node]) {
                if (dis[v] == 1e9) {
                    dis[v] = dis[node] + 1;
                    q.push(v);
                } else if (dis[node] <= dis[v]) {
                    ans = min(ans, dis[node] + dis[v] + 1);
                    if (dis[node] == dis[v])
                        return;
                }
            }
        }
    }

    int findShortestCycle(int n1, vector<vector<int>>& edges) {
        n = n1;
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        ans = 1e9;
        for (int i = 0; i < n; i++) {
            dis.assign(n + 1, 1e9);
            bfs(i);
        }
        return (ans == 1e9 ? -1 : ans);
    }
};
#include <bits/stdc++.h>
using namespace std;

//lc787
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // create adjacency list
        vector<pair<int, int>> adj[n];
        for (auto i : flights) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v, wt});
        }
        // {stops, {node, distance}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            if (stops > k) {
                continue;
            }

            for (auto i : adj[node]) {
                int adjNode = i.first;
                int weight = i.second;

                if (cost + weight < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + weight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        if (dist[dst] == 1e9) {
            return -1;
        }
        return dist[dst];
    }
};
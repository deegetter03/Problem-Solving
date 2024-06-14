#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        vector<vector<pair<int, bool>>> adj(n + 1);
        for (vector<int> &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v, false});
            adj[v].push_back({u, true});
        }

        deque<pair<int, int>> dq;
        vector<int> dist(n + 1, INT_MAX);
        dq.push_back({0, src});
        dist[src] = 0;

        while (!dq.empty())
        {
            int d = dq.front().first;
            int node = dq.front().second;
            dq.pop_front();

            if (node == dst)
                return d;

            for (pair<int, bool> &it : adj[node])
            {
                int adjNode = it.first;
                bool isReverse = it.second;
                if (dist[node] + isReverse < dist[adjNode])
                {
                    dist[adjNode] = dist[node] + isReverse;
                    if (isReverse)
                    {
                        dq.push_back({dist[adjNode], adjNode});
                    }
                    else
                        dq.push_front({dist[adjNode], adjNode});
                }
            }
        }
        return -1;
    }
};
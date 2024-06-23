#include <bits/stdc++.h>
using namespace std;
//lc1514

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

        // Adjacency list of graph
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double pb = succProb[i];

            adj[u].push_back({v, pb});
            adj[v].push_back({u, pb});
        }

        // creating probability vector of each node, initially all are zero
        // except the start node
        vector<double> probs(n, 0);
        probs[start] = 1;

        // creating a priority queue which sort on basis of highes probability
        // first and pushing the start
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        // iterating while there are nodes in pq
        while (!pq.empty()) {
            int nd = pq.top().second;
            double cpb = pq.top().first;
            pq.pop();

            // iterating over the adjacent nodes and pushing them to pq if
            // probability is increased
            for (auto& it : adj[nd]) {
                if (probs[it.first] < cpb * it.second) {
                    probs[it.first] = cpb * it.second;
                    pq.push({probs[it.first], it.first});
                }
            }
        }
        return probs[end];
    }
};
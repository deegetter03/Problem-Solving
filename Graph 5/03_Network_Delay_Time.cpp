#include <bits/stdc++.h>
using namespace std;

//lc743
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto it : times)
            adj[it[0]].push_back({it[1], it[2]});
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if (t + wt < time[adjNode]) {
                    time[adjNode] = t + wt;
                    pq.push({t + wt, adjNode});
                }
            }
        }
        int minTime = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9)
                return -1;
            minTime = max(time[i], minTime);
        }
        return minTime;
    }
};
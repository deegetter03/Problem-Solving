#include <bits/stdc++.h>
using namespace std;

//lc3112
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        // adj list
        unordered_map<int, vector<pair<int, int>>> list;
        for (auto it : edges) {
            list[it[0]].push_back({it[1], it[2]});
            list[it[1]].push_back({it[0], it[2]});
        }
        vector<int> ans(n, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            // take elements from the queue
            auto [time, node] = pq.top();
            pq.pop();

            if (ans[node] != -1)
                continue;

            ans[node] = time;

            for (auto& neighbor : list[node]) {
                int nnode = neighbor.first;
                int edgetime = neighbor.second;

                if (time + edgetime < disappear[nnode] && ans[nnode] == -1) {
                    pq.push({time + edgetime, nnode});
                }
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

//lc399
class Solution {
public:
    void dfs(string& s, string& d, unordered_map<string, vector<pair<string, double>>>& adj, set<string>& vis, double& ans, double temp) {
        if (vis.find(s) != vis.end()) {
            return;
        } else {
            vis.insert(s);
            if (s == d) {
                ans = temp;
                return;
            } else {
                for (auto nbr : adj[s]) {
                    dfs(nbr.first, d, adj, vis, ans, temp * nbr.second);
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // DFS Laga Do agr forward edge hai to value as a weight le lo
        // and backward edge k liye 1/value kar d0
        // O(n2) Tc lage gi.

        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < equations.size(); i++) {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        vector<double> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            string s = queries[i][0];
            string d = queries[i][1];
            set<string> vis;
            double ans = -1.0;
            if (adj.find(s) != adj.end())
                dfs(s, d, adj, vis, ans, 1.0);
            res[i] = ans;
        }
        return res;
    }
};
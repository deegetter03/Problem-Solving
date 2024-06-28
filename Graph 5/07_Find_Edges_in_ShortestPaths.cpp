#include <bits/stdc++.h>
using namespace std;

//lc3123
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<int>> b(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            b[edges[i][0]].push_back(i);
            b[edges[i][1]].push_back(i);
        }

        vector<int> c(n, INT_MAX);
        c[0] = 0;
        // get max
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first < n - 1) {
                for (int i : b[p.first]) {
                    int inext = edges[i][0];
                    int dist = edges[i][2];
                    if (inext == p.first)
                        inext = edges[i][1];
                    if (c[inext] > p.second + dist) {
                        c[inext] = p.second + dist;
                        q.push({inext, c[inext]});
                    }
                }
            }
        }
        vector<bool> way(edges.size(), false);
        q.push({n - 1, c[n - 1]});
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            if (p.first > 0) {
                for (int i : b[p.first]) {
                    int iback = edges[i][0];
                    int dist = edges[i][2];
                    if (iback == p.first)
                        iback = edges[i][1];
                    if (c[iback] == p.second - dist) {
                        way[i] = true;
                        q.push({iback, c[iback]});
                    }
                }
            }
        }
        return way;
    }
};
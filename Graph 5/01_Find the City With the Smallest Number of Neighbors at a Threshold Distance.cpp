#include <bits/stdc++.h>
using namespace std;
//lc1334

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> adj(n, vector<int>(n, 1e6));
        int m = edges.size();
        for (int i = 0; i < m; i++) {
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int i = 0; i < n; i++) {
            adj[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (adj[i][j] > adj[i][k] + adj[k][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
        int ans = -1;
        int mn = n + 1;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (adj[i][j] <= distanceThreshold)
                    c++;
            }
            if (c <= mn) {
                mn = c;
                ans = i;
            }
        }
        return ans;
    }
};
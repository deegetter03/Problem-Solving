#include <bits/stdc++.h>
using namespace std;

//lc684
class DisjointSet {
    public: 
        vector<int> parent;
        DisjointSet(int n) {
            parent.resize(n+1);

            for(int i=0;i<n;i++) {
                parent[i] = i;
            }
        }
        int findUPar(int node) {
            if(parent[node] == node)
                return node;

            return parent[node] = findUPar(parent[node]);
        }
        void unionBySmallerSize(int u,int v) {
            int ultU = findUPar(u);
            int ultV = findUPar(v);

            if(ultU == ultV)
                return;

            if(ultU < ultV) {
                parent[ultV] = ultU;
            }
            else {
                parent[ultU] = ultV;
            }
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> ans;

        for(int i=0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if(ds.findUPar(u) == ds.findUPar(v)) {
                ans.push_back(u);
                ans.push_back(v);
            } 
            else {
                ds.unionBySmallerSize(u,v);
            }
        }
        return ans;
    }
};
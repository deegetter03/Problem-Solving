#include <bits/stdc++.h>
using namespace std;
// lc2192

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adjList, vector<int> &temp, vector<int> &vis)
    {
        vis[node] = 1;
        temp.push_back(node);
        for (auto it : adjList[node])
        {
            if (!vis[it])
            {
                dfs(it, adjList, temp, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adjList(n);
        vector<vector<int>> ans(n);
        for (auto it : edges)
        {
            adjList[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            vector<int> vis(n, 0);
            dfs(i, adjList, temp, vis);
            auto it = temp.begin();
            temp.erase(it);
            sort(temp.begin(), temp.end());
            ans[i] = temp;
        }
        return ans;
    }
};
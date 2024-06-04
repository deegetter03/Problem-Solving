#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &vis, int &ans, int &maxi, int &k)
{
    vis[node] = true;
    ans++;
    if (maxi < ans)
    {
        maxi = ans;
        k = node;
    }
    for (auto it : graph[node])
    {
        if (!vis[it])
        {
            dfs(it, graph, vis, ans, maxi, k);
        }
    }
    ans--;
}
int solve(vector<int> &A)
{
    int n = A.size();
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            graph[i].push_back(A[i]);
            graph[A[i]].push_back(i);
        }
    }

    int ans = 0, maxi = 0, k = 0;
    vector<bool> vis(n, false);
    dfs(0, graph, vis, ans, maxi, k);
    ans = 0;
    maxi = 0;
    vector<bool> vis2(n, false);
    dfs(k, graph, vis2, ans, maxi, k);

    return maxi - 1;
}
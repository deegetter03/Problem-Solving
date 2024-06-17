#include <bits/stdc++.h>
using namespace std;

// METHOD 1
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return cnt < V ? true : false;
    }
};

//METHOD 2
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i, vector<int> adj[], vector<int> &vis)
    {
        vis[i] = 2;
        for (auto j : adj[i])
        {
            if (vis[j] == 0 and dfs(j, adj, vis))
                return true;
            else if (vis[j] == 2)
            {
                return true;
            }
        }
        vis[i] = 1;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                if (dfs(i, adj, vis))
                    return true;
            }
        }
        return false;
    }
};
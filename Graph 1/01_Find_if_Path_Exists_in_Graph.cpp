#include <bits/stdc++.h>
using namespace std;

// lc1971
// METHOD 1
// dfs
class Solution
{
public:
    bool dfs(vector<int> adj[], int source, int destination, vector<int> &visited)
    {
        visited[source] = 1;
        for (auto adjNode : adj[source])
        {
            if (adjNode == destination)
            {
                return true;
            }
            if (!visited[adjNode] && dfs(adj, adjNode, destination, visited))
            {
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (source == destination)
        {
            return true;
        }
        vector<int> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        return dfs(adj, source, destination, visited);
    }
};

// METHOD 2
// bfs
class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> adj[n];
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr == destination)
            {
                return true;
            }
            for (auto adjNode : adj[curr])
            {
                if (!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        return false;
    }
};
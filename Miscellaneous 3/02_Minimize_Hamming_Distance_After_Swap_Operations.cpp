#include <bits/stdc++.h>
using namespace std;
// lc1722

class Solution
{
public:
    void dfs(int curr, vector<int> adjList[], vector<bool> &visited, vector<int> &source, vector<int> &target, unordered_map<int, int> &Map)
    {
        if (visited[curr])
            return;
        visited[curr] = true;
        Map[target[curr]]++;
        Map[source[curr]]--;
        if (Map[target[curr]] == 0)
            Map.erase(target[curr]);
        if (Map[source[curr]] == 0)
            Map.erase(source[curr]);
        for (int next : adjList[curr])
        {
            dfs(next, adjList, visited, source, target, Map);
        }
    }
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps)
    {
        int n = source.size();
        vector<bool> visited(n);
        vector<int> adjList[n];
        for (vector<int> edge : allowedSwaps)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> Map;
            dfs(i, adjList, visited, source, target, Map);
            for (auto iter : Map)
            {
                ans += abs(iter.second);
            }
        }
        return ans >> 1;
    }
};
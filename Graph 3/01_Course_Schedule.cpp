#include <bits/stdc++.h>
using namespace std;
//lc207

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        if (p.size() == 0)
            return true; // all courses independent

        vector<int> indegree(
            n, 0); // counts the number of edges approaching a particular node
        vector<vector<int>> graph(n); // adjacency matrix of the given graph

        for (auto& x : p) {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i), indegree[i]--;
        }
        if (q.size() == 0)
            return false; // cycle exists if there is no node with indegree 0

        int count = 0; // No. of nodes you're able to reach till the end
        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                count++;
                for (auto child : graph[curr]) {
                    indegree[child]--; // decrement the indegree of the nodes until you've reached all nodes
                    if (indegree[child] == 0)
                        q.push(child);
                }
            }
        }
        if (count == n)
            return true;
        return false;
    }
};
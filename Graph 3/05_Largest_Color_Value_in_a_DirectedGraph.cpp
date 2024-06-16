#include <bits/stdc++.h>
using namespace std;
//lc1857

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<unordered_set<int>> adjList(n);
        vector<int> inDegree(n, 0);
        for (auto& e : edges)
            adjList[e[0]].insert(e[1]), inDegree[e[1]]++;

        queue<int> qu;
        vector<vector<int>> countColors(n, vector<int>(26));
        for (int i = 0; i < n; i++)
            if (inDegree[i] == 0)
                qu.push(i), countColors[i][colors[i] - 'a']++;

        int parent, colorIndex, maxColor = 1, totalNodes = 0;
        for (int size = qu.size(); !qu.empty(); size = qu.size()) {
            totalNodes += size;
            while (size--) {
                parent = qu.front();
                qu.pop();
                for (auto& child : adjList[parent]) {
                    // index of colors[child] in the 'countIndex[child]' array
                    colorIndex = colors[child] - 'a'; 
                    for (int i = 0; i < 26; i++)
                        countColors[child][i] = max(countColors[child][i], countColors[parent][i] + (i == colorIndex));
                    maxColor = max(maxColor, countColors[child][colorIndex]);

                    inDegree[child]--;
                    if (inDegree[child] == 0)
                        qu.push(child);
                }
            }
        }
        return totalNodes == n ? maxColor : -1;
    }
};
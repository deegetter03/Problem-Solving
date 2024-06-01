#include <bits/stdc++.h>
using namespace std;

//lc1557

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> answer;
        vector<int> indegree(n);
        for (auto& edge : edges) {
            indegree[edge[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                answer.push_back(i);
            }
        }
        return answer;
    }
};
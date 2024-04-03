#include<bits/stdc++.h>
using namespace std;

//METHOD1
class Solution {
public:
    int equalSubstring(string str, string tar, int maxCost) {
        int n = str.size();
        int i=0, j=0, ans = 0, cost = 0;
        for (j = 0; j < n; j++) {
            cost += abs(str[j] - tar[j]);
            for (; cost > maxCost; i++)
                cost -= abs(str[i] - tar[i]);
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

//METHOD2
class Solution {
public:
    int equalSubstring(string str, string tar, int maxCost) {
        int n = str.size();
        int start = 0;
        int currentcost = 0;
        int maxx = 0;

        // sliding window ka concept use krna h
        for (int end=0; end<n; end++) {
            currentcost += abs(str[end] - tar[end]);
            while (start <= end && currentcost > maxCost) { //sliding window shrink kro
                currentcost -= abs(str[start] - tar[start]);
                start++;
            }
            maxx = max({maxx, end - start + 1});
        }
        return maxx;
    }
};
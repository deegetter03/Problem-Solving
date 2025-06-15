#include <bits/stdc++.h>
using namespace std;
//lc1423

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0, rightsum = 0, maxsum = 0;
        for (int i = 0; i < k; i++) {
            leftsum = leftsum + cardPoints[i];
            maxsum = leftsum;
        }
        int rightindex = cardPoints.size() - 1;
        for (int i = k - 1; i >= 0; i--) {
            leftsum = leftsum - cardPoints[i];
            rightsum = rightsum + cardPoints[rightindex];
            rightindex--;
            maxsum = max(maxsum, leftsum + rightsum);
        }
        return maxsum;
    }
};
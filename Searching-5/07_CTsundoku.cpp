#include <bits/stdc++.h>
using namespace std;

int count(vector<long long>& deskB, long long k) {
    int low = 0;
    int high = deskB.size() - 1;
    int ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (deskB[mid] <= k) {
            ans = mid;
            low = mid + 1;
        } 
        else
            high = mid - 1;
    }
    return ans;
}

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    vector<long long> deskA(n + 1, 0);
    vector<long long> deskB(m + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> deskA[i];
        deskA[i] += deskA[i - 1];
    }

    for (int i = 1; i <= m; i++) {
        cin >> deskB[i];
        deskB[i] += deskB[i - 1];
    }

    int maxbook = 0;
    for (int i = 0; i <= n; i++) {
        long long costRemains = k - deskA[i];
        if (costRemains < 0) {
            break;
        }
        int bookB = count(deskB, costRemains);
        maxbook = max(maxbook, i + bookB);
    }
    cout << maxbook << endl;
    return 0;
}
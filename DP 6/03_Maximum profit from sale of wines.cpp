#include <bits/stdc++.h>
using namespace std;
//gfg

#include <bits/stdc++.h>
using namespace std;

#define N 1000

int dp[N][N]; // Dynamic programming table for storing maximum profits
int sell[N][N]; // Table for storing information about when to sell

int maxProfit(int price[], int n) {
    for (int i = 0; i < n; i++) {
        dp[i][i] = n * price[i];
        sell[i][i] = 0;
    }

    for (int len = 1; len < n; len++) {
        for (int i = 0; i < n - len; i++) {
            int j = i + len;
            int year = n - (j - i);

            int x = price[i] * year + dp[i + 1][j];
            int y = price[j] * year + dp[i][j - 1];

            if (x >= y) {
                dp[i][j] = x;
                sell[i][j] = 0;
            } else {
                dp[i][j] = y;
                sell[i][j] = 1;
            }
        }
    }

    int i = 0, j = n - 1;
    while (i <= j) {
        if (sell[i][j] == 0) {
            cout << "beg ";
            i++;
        } else {
            cout << "end ";
            j--;
        }
    }
    cout << endl;

    return dp[0][n - 1];
}

int main() {
    int price[] = {2, 4, 6, 2, 5};
    int n = sizeof(price) / sizeof(price[0]);
    int ans = maxProfit(price, n);
    cout << ans << endl;
    return 0;
}
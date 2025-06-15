#include <bits/stdc++.h>
using namespace std;

// CPP program to find the maximum value of
// x*arr[i] + y*arr[j] + z*arr[k]

// function to maximize the condition
int maximizeExpr(int a[], int n, int x, int y, int z)
{
    // Traverse the whole array and compute
    // left maximum for every index.
    int L[n];
    L[0] = x * a[0];
    for (int i = 1; i < n; i++)
        L[i] = max(L[i - 1], x * a[i]);
        
    // Compute right maximum for every index.
    int R[n];
    R[n - 1] = z * a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        R[i] = max(R[i + 1], z * a[i]);

    // Traverse through the whole array to
    // maximize the required expression.
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
        ans = max(ans, L[i] + y * a[i] + R[i]);

    return ans;
}

// driver program to test the above function
int main()
{
    int a[] = {-1, -2, -3, -4, -5};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 1, y = 2, z = -3;
    cout << maximizeExpr(a, n, x, y, z) << endl;
    return 0;
}

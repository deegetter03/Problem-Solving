#include <bits/stdc++.h>
using namespace std;

// METHOD1
int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans[ans.size() / 2]; // median mil jayega
}

// METHOD2

int occurrence_in_rows(vector<int> matrix, int x, int col)
{
    int low = 0, high = col - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[mid] <= x) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int occurrence(vector<vector<int>> &matrix, int mid, int row, int col)
{
    int count = 0;
    for (int j = 0; j < row; j++)
    {
        count += occurrence_in_rows(matrix[j], mid, col);
    }
    return count;
}

int median(vector<vector<int>> &matrix, int n, int m)
{
    int low = INT_MAX, high = INT_MIN;
    int req = m * n / 2;
    for (int i = 0; i < n; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m - 1]);
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (req >= occurrence(matrix, mid, n, m)) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}
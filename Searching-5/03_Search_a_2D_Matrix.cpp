#include <bits/stdc++.h>
using namespace std;

// METHOD1
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // run nested loop and get the element   //basic sol.
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

// METHOD2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0;
        while (i < n)
        {
            if (target <= matrix[i][m - 1])
            {
                int j = 0;
                while (j < m)
                {
                    if (target == matrix[i][j])
                        return true;
                    else if (target < matrix[i][j])
                        return false;
                    else
                        j++;
                }
                return false;
            }
            i++;
        }

        return false;
    }
};

// METHOD3
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // best
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / m; // to convert index 1d to 2d
            int col = mid % m;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
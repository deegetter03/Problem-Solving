#include <bits/stdc++.h>
using namespace std;
// lc881

class Solution
{
public:
    int numRescueBoats(vector<int> &arr, int limit)
    {
        sort(arr.begin(), arr.end());
        int start = 0;
        int end = arr.size() - 1;
        int count = 0;
        while (start <= end)
        {
            if (arr[start] + arr[end] <= limit)
            {
                count++;
                start++;
                end--;
            }
            else
            {
                count++;
                end--;
            }
        }
        return count;
    }
};
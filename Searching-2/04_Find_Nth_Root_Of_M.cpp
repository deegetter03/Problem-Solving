// METHOD:-1
int NthRoot(int n, int m)
{
    // Handle edge case where m is 0 or 1
    if (m == 0 || m == 1)
        return m;
    int low = 1;
    int high = m;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long power = 1;
        for (int i = 0; i < n; ++i)
        {
            if (power > m / mid)
            {
                power = m + 1; // Break the loop if power exceeds m
                break;
            }
            power *= mid;
        }
        if (power == m)
        {
            result = mid;
            break;
        }
        else if (power < m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

// METHOD:-2
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
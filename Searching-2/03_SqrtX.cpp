//METHOD:-1
int floorSqrt(int n) {
    int ans = 0;
    for (long long i = 1; i <= n; i++) {
        long long value = i * i;
        if (value <= n * 1LL)
            ans = i;
        else
            break;
    }
    return ans;
}

//METHOD:-2
class Solution {
public:
    int mySqrt(int n) {
        int low = 1, high = n;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long value = mid*mid;   //to handle overflow
            if (value <= n)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
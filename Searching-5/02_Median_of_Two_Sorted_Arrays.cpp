#include<bits/stdc++.h>
using namespace std;

//METHOD1
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        //naive
        vector<int> c;
        int n1 = a.size(), n2 = b.size();
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                c.push_back(a[i++]); // a[i];i++;
            } else
                c.push_back(b[j++]);
        }
        while (i < n1)
            c.push_back(a[i++]);
        while (j < n2)
            c.push_back(b[j++]);
        int n = n1 + n2;
        if (n % 2 == 1)
            return c[n / 2]; // odd case
        // else
        return (double)((double)(c[n / 2]) + (double)(c[n / 2 - 1])) / 2.0;
    }
};


//METHOD2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        if (n1 > n2)
            return findMedianSortedArrays(b, a);
        int low = 0, high = n1;
        int left = (n + 1) / 2;

        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = a[mid1];
            if (mid2 < n2)
                r2 = b[mid2];
            if (mid1 - 1 >= 0)
                l1 = a[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = b[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
            } else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }
};
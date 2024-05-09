#include <bits/stdc++.h>
using namespace std;

// METHOD1
bool hasOnlyOneChild(int pre[], int size) {
  int nextDiff, lastDiff;
  for (int i = 0; i < size - 1; i++)
  {
    nextDiff = pre[i] - pre[i + 1];
    lastDiff = pre[i] - pre[size - 1];
    if (nextDiff * lastDiff < 0)
      return false;
  }
  return true;
}

// METHOD2
bool hasOnlyOneChild(int pre[], int size)
{
  int max_val = INT_MAX, min_val = INT_MIN;
  for (int i = 1; i < size; i++)
  {
    if (pre[i] < min_val || pre[i] > max_val)
      return false;
    if (pre[i] < pre[i - 1])
      max_val = pre[i - 1];
    else
      min_val = pre[i - 1];
  }
  return true;
}
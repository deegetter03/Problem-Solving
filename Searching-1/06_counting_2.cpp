//METHOD:-1

#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& nums, int n)
{
	int low = 0, high = nums.size() - 1, ans = nums.size();
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (nums[mid] >= n)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low= mid + 1;
	}
	return ans;
}
int main()
{
	int n, q;
	cin >> n >> q;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
	sort(nums.begin(), nums.end());
	for (int i = 0; i < q; i++)
	{
		int t;
		cin >> t;
		cout << n - solve(nums, t) << endl;
	}
	return 0;
}
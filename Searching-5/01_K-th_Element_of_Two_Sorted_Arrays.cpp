#include<bits/stdc++.h>
using namespace std;

//METHOD:-1
int kthElement(vector<int> &arr1, vector<int>& arr2, int n1, int n2, int k){
    vector<int> arr3;
    int i=0, j=0;

    while(i<n1 && j<n2){
        if(arr1[i] < arr2[j])
            arr3.push_back(arr1[i++]);   //arr1[i];i++;
        else
            arr3.push_back(arr2[j++]);
    }
    while(i<n1) arr3.push_back(arr1[i++]);
    while(j<n2) arr3.push_back(arr2[j++]);

    return arr3[k-1];  //value
}

//METHOD:-2
#include <bits/stdc++.h>
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k){
	if(n1 > n2) return kthElement(b,a,n2,n1,k); // Swap arrays to ensure n1 <= n2
    int n = n1+n2;
	int low = max(0,k-n2), high = min(k, n1);
	
	while(low<=high){
		int mid1 =(low+high)>>1;
		int mid2 =k-mid1;
		int l1 = INT_MIN, l2 = INT_MIN;
		int r1 = INT_MAX, r2 = INT_MAX;

		if(mid1 <n1) r1 =a[mid1];
		if(mid2 <n2) r2 =b[mid2];
		if(mid1-1 >= 0) l1 =a[mid1-1];
		if(mid2-1 >= 0) l2 =b[mid2-1];

		if(l1 <= r2 && l2 <= r1){
			return max(l1, l2);
		}
		else if(l1 > r2) high = mid1-1;
		else low = mid1+1;
	}
	return 0;
}
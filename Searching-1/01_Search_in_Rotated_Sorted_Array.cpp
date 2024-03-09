METHOD:-1

int LinearSearch(vector<int>& arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}



METHOD:-2
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return mid;
            if(arr[low]<=arr[mid]){ //means left wala sorted hai
                if(arr[low]<=target && target<=arr[mid])
                    high = mid-1;   //ab left side jayega
                else
                    low = mid+1;
            }
            else{ // arr[mid] <= arr[high]  right wala sorted hai
                if(arr[mid]<=target && target<=arr[high])
                    low = mid+1;  //ab right jayega
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};
METHOD:-1 
int first = -1, last = -1;
for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
        if (first == -1) first = i;
        last = i;
    }
}

METHOD:-2
class Solution {
public:
    int firstposition(vector<int>& arr, int target){
        int low=0,high=arr.size()-1;
        int first=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                first = mid;
                high=mid-1; //for checking the left side
            }
            else if(arr[mid] < target){
                low=mid+1;
            }
            else  //arr[mid]>target
                high=mid-1;
        }
        return first;
    }

    int lastposition(vector<int>& arr, int target){
        int low=0,high=arr.size()-1;
        int last=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                last = mid;
                low=mid+1; //for checking the right side
            }
            else if(arr[mid] < target){
                low=mid+1;
            }
            else  //arr[mid]>target
                high=mid-1;
        }
        return last;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int first = firstposition(arr,target);
        if(first == -1) return {-1,-1};  //means element nhi hai
        int last = lastposition(arr,target);
        return {first, last};
    }
};
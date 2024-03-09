METHOD1:-

int mini = INT_MAX;
for (int i = 0; i < n; i++) {
    mini = min(mini, arr[i]);
}
return mini;

METHOD:-2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid  = (low+high)/2;
            if(nums[low]<=nums[high]){ //array is already sorted
                ans = min(ans, nums[low]);
                break;
            }
            if( nums[low]<=nums[mid]){  // left side sorted hai
                ans = min(ans, nums[low]);
                low = mid+1;
            }
            //  nums[mid]<=nums[high]) means  // right side sorted hai
            else{
                ans = min(ans, nums[mid]);
                high = mid-1;
            }
        }
        return ans;
    }
};
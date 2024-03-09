//METHOD:-1
int PeakElement(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == arr.size() - 1 || arr[i] > arr[i + 1]))
            return i;
    }
}

//METHOD:-2
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        int low=1, high=n-2;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            else if(nums[mid] > nums[mid-1]) low=mid+1;
            else high = mid-1;
        }
        return -1;
    }
};
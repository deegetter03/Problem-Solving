METHOD:-1 use linear search and get the element


METHOD:-2
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[low] == nums[mid] &&
                nums[mid] == nums[high]) { // for handling the duplicate cases
                low++;
                high--;
                continue;
            }
            if (nums[low] <= nums[mid]) { // left sorted hai
                if (nums[low] <= target && target <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            } else {
                if (nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};
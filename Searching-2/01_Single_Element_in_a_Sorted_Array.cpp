//METHOD:-1  using XOR

int singleElement(vector<int>& arr) {
    int ans = 0;
    // XOR all the elements:
    for (int i = 0; i < arr.size(); i++) {
        ans = ans ^ arr[i];
    }
    return ans;
}

//METHOD:-2 

int singleElement(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {
        //Check for first index edge case:
        if (i == 0) {
            if (arr[i] != arr[i + 1])
                return arr[i];
        }
        //Check for last index:
        else if (i == n - 1) {
            if (arr[i] != arr[i - 1])
                return arr[i];
        }
        else {
            if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                return arr[i];
        }
    }
}


//METHOD:-3 optimal

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        if (arr[0] != arr[1])
            return arr[0];
        if (arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
                return arr[mid];

            // for left side
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) ||
                (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                low = mid + 1;
            }
            // right
            else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
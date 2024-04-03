//METHOD :-1 brute
int countRotations(int arr[], int n) 
{ 
    int min = arr[0], min_index = 0; 
    for (int i = 0; i < n; i++) { 
        if (min > arr[i]) { 
            min = arr[i]; 
            min_index = i; 
        } 
    } 
    return min_index; 
} 


//METHOD:-2
int countRotations(int arr[], int n) { 
    int low = 0, high = n - 1; 
    while (low <= high) { 
        if (arr[low] <= arr[high]) return low; 
        int mid = low + (high - low) / 2; 
        int next = (mid + 1) % n, prev = (mid + n - 1) % n; 
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) return mid; 
        else if (arr[mid] <= arr[high]) high = mid - 1; 
        else low = mid + 1; 
    } 
    return -1; 
} 

//METHOD:-1

bool canplace(vector<int> &stalls, int dist, int cows){
    int countcows=1, last=stalls[0];
    for(int i=1; i<stalls.size(); i++){
        if(stalls[i]-last >= dist){
            countcows++;
            last = stalls[i];
        }
        if (countcows>=cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int low=1, high= stalls[stalls.size()-1]-stalls[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(canplace(stalls, mid, k) == true)
            low = mid+1;
        else
            high = mid-1;
    }
    return high;
}
// Time complexity O(2 * nlogn) + O(2 * n)
// Space complexity O(1)
// Here we are modifying the given array

int findPlatform(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);
    int count = 0, minPlatform = 1, i = 0, j = 0;
    while(i<n && j<n) {
        if(arr[i]<=dep[j]) {
            ++count;
            ++i;
            // we can add here also
            // minPlatform = max(minPlatform, count);
        }
        else {
            --count;
            ++j;
        }
        minPlatform = max(minPlatform, count);
    }
    return minPlatform;
}

// Time complexity O(2*nlog(2*n))
// Space complexity O(2*n)
int findPlatform(vector<int>& arr, vector<int>& dep) {
    int n = arr.size(), count = 0, maxCount = 0;
    int N = 2*n;
    vector<pair<int, char>> timing(N);
    for(int i=0; i<n; ++i) {
        timing[2*i] = {arr[i], 'a'};
        timing[2*i+1] = {dep[i], 'd'};
    }
    sort(timing.begin(), timing.end());
    for(pair<int, char> p : timing) {
        if(p.second=='a') {
            ++count;
            maxCount = max(maxCount, count);
        }
        else {
            --count;
        }
    }
    return maxCount;
}
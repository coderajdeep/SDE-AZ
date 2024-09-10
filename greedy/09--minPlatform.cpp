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
        }
        else {
            --count;
            ++j;
        }
        minPlatform = max(minPlatform, count);
    }
    return minPlatform;
}
// https://www.codingninjas.com/studio/problems/count-inversions_615
// Time complexity O(n^2)
// Space complexity O(1)
long long getInversions(long long *arr, int n){
    int count = 0;
    for(int i=0; i<n-1; ++i) {
        for(int j=i+1; j<n; ++j) {
            if(arr[i]>arr[j]) {
                ++count;
            }
        }
    }
    return count;
}

// Time complexity O(nlogn)
// Space complexity O(n)
long long merge(int low, int mid, int high, long long *arr, long long *temp) {
    for(int i=low; i<=mid; ++i) {
        temp[i] = arr[i];
    }
    for(int i=mid+1; i<=high; ++i) {
        temp[i] = arr[i];
    }
    int index = low, i = low, j = mid+1;
    long long count = 0;
    while(i<=mid && j<=high) {
        if(temp[i]<=temp[j]) {
            arr[index++] = temp[i++];
        }
        else {
            count += (mid - i + 1);
            arr[index++] = temp[j++];
        }
    }
    while(i<=mid) {
        arr[index++] = temp[i++];
    }
    while(j<=high) {
        arr[index++] = temp[j++];
    }
    return count;
}
long long mergeSort(int low, int high, long long *arr, long long *temp) {
    if(low>=high) return 0;
    long long count = 0;
    int mid = (high-low)/2 + low;
    count += mergeSort(low, mid, arr, temp);
    count += mergeSort(mid+1, high, arr, temp);
    count += merge(low, mid, high, arr, temp);
    return count;
}
long long getInversions(long long *arr, int n){
    long long *temp = new long long[n];
    long long ans = mergeSort(0, n-1, arr, temp);
    delete[] temp;
    return ans;
}
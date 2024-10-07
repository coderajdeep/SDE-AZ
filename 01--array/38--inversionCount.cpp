// Inversion count
// Time complexity O(nlogn)
// Space complexity O(n)

long long merge(long long start, long long mid, long long end, long long *temp, long long *arr) {
    for(int i=start; i<=end; ++i) {
        temp[i] = arr[i];
    }
    long long i = start, j = mid+1, k = start, count = 0;
    while(i<=mid && j<=end) {
        if(temp[i]<=temp[j]) {
            arr[k++] = temp[i++];
        }
        else {
            count += (mid-i+1);
            arr[k++] = temp[j++];
        }
    }
    while(i<=mid) {
        arr[k++] = temp[i++];
    }
    while(j<=end) {
        arr[k++] = temp[j++];
    }
    return count;
}
long long mergeSort(long long start, long long end, long long *temp, long long *arr) {
    // start<=end will leads to an infinite loop
    if(start<end) {
        long long count = 0, mid = start + (end-start)/2;
        count += mergeSort(start, mid, temp, arr);
        count += mergeSort(mid+1, end, temp, arr);
        count += merge(start, mid, end, temp, arr);
        return count;
    }
    return 0;
}
long long int inversionCount(int N, long long arr[]) {
    long long *temp = new long long [N];
    return mergeSort(0, N-1, temp, arr);
}
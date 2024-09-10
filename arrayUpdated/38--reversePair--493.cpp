// Reverse Pairs -- leetcode 493
// Time complexity O(nlogn)
// Space complexity O(n)
void merge(int start, int mid, int end, vector<int> &temp, vector<int> &arr) {
    for(int i=start; i<=end; ++i) {
        temp[i] = arr[i];
    }
    int i = start, j = mid+1, k = start;
    while(i<=mid && j<=end) {
        if(temp[i]<=temp[j]) {
            arr[k++] = temp[i++];
        }
        else {
            arr[k++] = temp[j++];
        }
    }
    while(i<=mid) {
        arr[k++] = temp[i++];
    }
    while(j<=end) {
        arr[k++] = temp[j++];
    }
}
int getCount(int start, int mid, int end, vector<int> &arr) {
    int i = start, j = mid+1, count = 0;
    while(i<=mid && j<=end) {
        if((long)arr[i] > (long)2 * (long)arr[j]) {
            count += (mid - i + 1);
            ++j;
        }
        else {
            ++i;
        }
    }
    return count;
}
int mergeSort(int start, int end, vector<int> &temp, vector<int> &arr) {
    // start<=end will leads to an infinite loop
    if(start<end) {
        int count = 0, mid = start + (end-start)/2;
        count += mergeSort(start, mid, temp, arr);
        count += mergeSort(mid+1, end, temp, arr);
        count += getCount(start, mid, end, arr);
        merge(start, mid, end, temp, arr);
        return count;
    }
    return 0;
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp(n);
    return mergeSort(0, n-1, temp, nums);
}
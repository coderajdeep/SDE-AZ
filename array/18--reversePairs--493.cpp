// leetcode 493
// Count Reverse Pais (Hard)

// Time complexity O(2*n*logn)
// Space complexity O(n)
int reversePairCount(int low, int mid, int high, vector<int>& nums) {
    int right = (mid + 1), count = 0;
    for(int left=low; left<=mid; ++left) {
        while((right<=high) && ((long)nums[left] > (2 * (long)nums[right]))) {
            ++right;
        }
        count += (right-mid-1);
    }
    return count;
}
void merge(int low, int mid, int high, vector<int>& nums, vector<int>& temp) {
    for(int i=low; i<=mid; ++i) {
        temp[i] = nums[i];
    }
    for(int i=mid+1; i<=high; ++i) {
        temp[i] = nums[i];
    }
    int index = low, i = low, j = mid+1;
    while(i<=mid && j<=high) {
        if(temp[i]<=temp[j]) {
            nums[index++] = temp[i++];
        }
        else {
            nums[index++] = temp[j++];
        }
    }
    while(i<=mid) {
        nums[index++] = temp[i++];
    }
    while(j<=high) {
        nums[index++] = temp[j++];
    }
}
int mergeSort(int low, int high, vector<int>& nums, vector<int>& temp) {
    if(low>=high) return 0;
    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(low, mid, nums, temp);
    count += mergeSort(mid+1, high, nums, temp);
    count += reversePairCount(low, mid, high, nums);
    merge(low, mid, high, nums, temp);
    return count;
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp(n);
    int ans = mergeSort(0, n-1, nums, temp);
    return ans;
}
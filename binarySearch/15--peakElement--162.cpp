// Find Peak Element - leetcode 162

// Time complexity O(n)
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 0;
    if(n==2) return (nums[0]<nums[1]?1:0);
    for(int i=0; i<n; ++i) {
        if(i==0) {
            if(nums[i]>nums[i+1]) {
                return i;
            }
        }
        else if(i==n-1) {
            if(nums[i]>nums[i-1]) {
                return i;
            }
        }
        else if(nums[i-1]<nums[i] && nums[i+1]<nums[i]) {
            return i;
        }
    }
    return -1;
}


// Time complexity O(logn)
int findPeakElement(vector<int>& nums) {
    // array elements are strictly increasing or decreasing
    int n = nums.size();
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int high = n-2, low = 1, mid;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]) {
            return mid;
        }
        if(nums[mid-1]<nums[mid]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}
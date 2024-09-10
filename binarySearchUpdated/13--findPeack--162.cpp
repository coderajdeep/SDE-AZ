// Find Peak element in array -- leetcode 162

// Time complexity O(logn)
// Space complexity O(1)
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
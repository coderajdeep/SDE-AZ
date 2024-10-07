// Find single element in sorted array -- leetcode 540

// Time complexity O(logn)
// Space complexity O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-2] != nums[n-1]) return nums[n-1];
    int low = 2, high = n-3;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) return nums[mid];
        // mid is odd
        if(mid & 1) {
            if(nums[mid]==nums[mid-1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        else {
            if(nums[mid]==nums[mid+1]) {
                low = mid + 2;
            }
            else {
                high = mid - 2;
            }
        }
    }
    return -1;
}

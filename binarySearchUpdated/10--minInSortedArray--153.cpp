// Find minimum in rotated sorted array - leetcode 153 (All elements are unique)
// If duplicate elements exist then we can't eleminate one part at a time
// We need to trim the array first when we can't decide which part is sorted

// Time complexity O(logn)
// Space complexity O(1)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1, mid, minElement = INT_MAX;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[low]<=nums[mid]) {
            minElement = min(minElement, nums[low]);
            low = mid + 1;
        }
        else {
            minElement = min(minElement, nums[mid]);
            high = mid - 1;
        }
    }
    return minElement;
}
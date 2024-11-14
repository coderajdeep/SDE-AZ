// Search in rotated sorted array - leetcode 33
 
// Time complexity O(logn)
// Space complexity O(logn)
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(nums[mid] == target) return mid;
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        else {
            if(nums[mid] < target && nums[high] >= target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
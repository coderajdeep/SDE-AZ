// Search in rotated sorted array - leetcode 81

// Time complexity Θ(logn) O(n)
// Space complexity O(1)

// [3 3 1 3 3 3 3 3 3 3]
// In this type of test case, we can't decide which part we need to eleminate
// So we need to trim from both side and here the algorithm will take linear time
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, mid;
    while(low<=high) {
        mid = low + (high-low)/2;
        if(nums[mid]==target) {
            return true;
        }
        if(nums[low]==nums[mid] && nums[high]==nums[mid]) {
            ++low;
            --high;
            continue;
        }
        if(nums[low]<=nums[mid]) {
            if(target<nums[mid] && target>=nums[low]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        else {
            if(target>nums[mid] && target<=nums[high]) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return false;
}
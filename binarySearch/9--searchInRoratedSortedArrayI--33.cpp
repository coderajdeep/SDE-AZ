// leetcode 33
// Search in sorted and rotated array (unique elements)

/*** test case
arr = [4,5,6,7,0,1,2], target = 0
arr = [1], target = 0
arr = [5,1,3], target = 5
arr = [3,1], target = 1
***/

// Time complexity O(logn)
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(nums[mid]==target) {
            return mid;
        }
        if(nums[low]<=nums[mid]) {
            // not this
            // (target <= nums[mid])
            // This is important
            // because nums[mid]!=target
            if((target < nums[mid]) && (target >= nums[low])) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
            
        }
        else {
            if((target > nums[mid]) && (target <= nums[high])) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
    }
    return -1;
}
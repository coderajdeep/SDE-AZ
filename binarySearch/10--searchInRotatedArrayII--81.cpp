// Search in sorted and rotated array II (duplicate elements)

// Time complexity O(n/2)
// Question? What if I need to return element index like lower_bound
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
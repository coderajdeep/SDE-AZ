// leetcode 35
// Find first insert position
// Basically implement a lower bound function

int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(target<nums[0]) {
        low = 0;
    }
    else if(target>nums[high-1]) {
        low = high;
    }
    else {
        while(low < high) {
            mid = low + (high - low) / 2;
            if(target <= nums[mid]) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return low;
}

// Same solution
int searchInsert(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(nums.front()>target) return 0;
    else if(nums.back()<target) return high;
    else {
        while(low<high) {
            mid = low + (high - low) / 2;
            if(nums[mid]>=target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
    return -1;
}
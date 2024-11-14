// Min element in rotated sorted array - leetcode 154 (duplicated elements allowed) 

// Time complexity O(n/2)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n-1, mid, minNum = INT_MAX;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[low]==nums[mid] && nums[mid]==nums[high]) {
            minNum = min(minNum, nums[low]);
            ++low;
            --high;
            continue;
        }
        if(nums[low]<=nums[mid]) {
            minNum = min(minNum, nums[low]);
            low = mid + 1;
        }
        else {
            minNum = min(minNum, nums[mid]);
            high = mid - 1;
        }
    }
    return minNum;
}
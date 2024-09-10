// 1
// Binary serach on array - leetcode 704

// Time complexity O(logn)
// Space complexity O(1)
// Iterative solution
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, mid;
    while(low<=high) {
        mid = low + (high-low)/2;
        if(nums[mid]==target) {
            return mid;
        }
        if(nums[mid]>target) {
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return -1;
}


// Time complexity O(logn)
// Space complexity O(logn) (Using function call stack)
// Recursive solution
int binarySearch(int low, int high, int target, vector<int>& nums) {
    if(low>high) {
        return -1;
    }
    int mid = low + (high-low)/2;
    if(nums[mid]==target) {
        return mid;
    }
    if(nums[mid]>target) {
        return binarySearch(low, mid-1, target, nums);
    } 
    else {
        return binarySearch(mid+1, high, target, nums);
    }
}
int search(vector<int>& nums, int target) {
    return binarySearch(0, nums.size()-1, target, nums);
}
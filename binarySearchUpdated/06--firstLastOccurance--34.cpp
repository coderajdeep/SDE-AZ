// First and last occurance in array - leetcode 34
// Time complexity O(2 * logn)
// Space complexity O(1)
// Better solution
int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(nums.front() > target) return 0;
    else if(nums.back() < target) return high;
    else {
        while(low<high) {
            mid = low + (high - low)/2;
            if(nums[mid] >= target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    return -1;
}
int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(nums.front() > target) return 0;
    else if(nums.back() < target) return high;
    else {
        while(low<high) {
            mid = low + (high - low)/2;
            if(nums[mid]<=target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    if(nums.empty()) return vector<int> {-1, -1};
    
    int low = lowerBound(nums, target);
    // not present
    if(low == nums.size()) return vector<int> {-1, -1};

    // not present
    if(nums[low] != target) return vector<int> {-1, -1};
    
    int high = upperBound(nums, target);

    // present
    return vector<int> {low, high-1};
}


// Time complexity O(2 * logn)
// Space complexity O(1)

int lowerBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(high==0) return -1;
    else if(nums.front() > target) return 0;
    else if(nums.back() < target) return high;
    else {
        while(low<high) {
            mid = low + (high - low)/2;
            if(nums[mid] >= target) high = mid;
            else low = mid + 1;
        }
        return low;
    }
    return -1;
}
int upperBound(vector<int>& nums, int target) {
    int low = 0, high = nums.size(), mid;
    if(high==0) return -1;
    else if(nums.front() > target) return 0;
    else if(nums.back() < target) return high;
    else {
        while(low<high) {
            mid = low + (high - low)/2;
            if(nums[mid]<=target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int low = lowerBound(nums, target);

    // not present
    if(low == nums.size()) return vector<int> {-1, -1};

    int high = upperBound(nums, target);

    // not present
    if(low == high) return vector<int> {-1, -1};

    // present
    return vector<int> {low, high-1};
}
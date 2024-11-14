// leetcode 34
// First and last occurance of an element in an sorted array 

// Best approach
int lowerBound(int low, int high, int target, vector<int>& nums) {
    int mid;
    if(target<=nums[0]) {
        low = 0;
    }
    else if(target>nums[high-1]) {
        low = high;
    }
    else {
        while(low<high) {
            mid = low + (high-low)/2;
            if(target<=nums[mid]) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
    }
    return low;
}
int upperBound(int low, int high, int target, vector<int>& nums) {
    int mid;
    if(target<nums[0]) {
        low = 0;
    }
    else if(target>=nums[high-1]) {
        low = high;
    }
    else {
        while(low<high) {
            mid = low + (high-low)/2;
            if(target>=nums[mid]) {
                low = mid+1;
            }
            else {
                high = mid;
            }
    }
    }
    return low;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if(n==0) return {-1, -1};
    int lowerBoundIndex = lowerBound(0, n, target, nums);
    if(lowerBoundIndex==n) return {-1, -1};
    else if(target!=nums[lowerBoundIndex]) return {-1, -1};
    int upperBoundIndex = upperBound(lowerBoundIndex, n, target, nums);
    return {lowerBoundIndex, (upperBoundIndex-1)};
}

// Using own lower_bound and upper_bound
// Time complexity O(logn)
int lowerBound(int n, int target, vector<int>& nums) {
    int low = 0, high = n, mid;
    if(target<=nums[0]) {
    low = 0;
    }
    else if(target>nums[n-1]) {
    low = n;
    }
    else {
    while(low<high) {
        mid = low + (high-low)/2;
        if(target<=nums[mid]) {
        high = mid;
        }
        else {
        low = mid+1;
        }
    }
    }
    return low;
}
int upperBound(int n, int target, vector<int>& nums) {
    int low = 0, high = n-1, mid;
    if(target<nums[0]) {
    low = 0;
    }
    else if(target>=nums[n-1]) {
    low = n;
    }
    else {
    while(low<high) {
        mid = low + (high-low)/2;
        if(target>=nums[mid]) {
        low = mid+1;
        }
        else {
        high = mid;
        }
    }
    }
    return low;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if(n==0) return {-1, -1};
    int lowerBoundIndex = lowerBound(n, target, nums);
    if(lowerBoundIndex==n) return {-1, -1};
    else if(target!=nums[lowerBoundIndex]) return {-1, -1};
    int upperBoundIndex = upperBound(n, target, nums);
    return {lowerBoundIndex, (upperBoundIndex-1)};
}

// Using STL lower_bound() and upper_bound()
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if(n==0) return {-1, -1};
    vector<int>::iterator begin = nums.begin();
    int lowerBound = lower_bound(nums.begin(), nums.end(), target) - begin;
    if(lowerBound==n) return {-1, -1};
    else if(nums[lowerBound]!=target) return {-1, -1};
    int upperBound = upper_bound(nums.begin()+lowerBound, nums.end(), target) - begin;
    return {lowerBound, (upperBound-1)};
}
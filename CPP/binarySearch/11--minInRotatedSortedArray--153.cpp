// Min element in rotated sorted array - leetcode 153


// Time complexity O(logn)
// Striver approach
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1, mid;
    int minNum = 1e9;
    while(low<=high) {
        mid = low + (high - low) / 2;
        if(nums[low]<=nums[mid]) {
            minNum = min(nums[low], minNum);
            low = mid + 1;
        }
        else {
            minNum = min(nums[mid], minNum);
            high = mid - 1;
        }
    }
    return minNum;
}

// My code school
int findMin(vector<int>& nums) {
    int n = nums.size();
    int lo = 0, hi = n-1;
    
    while(lo<=hi) {
        if(nums[lo]<=nums[hi]) {
            return nums[lo];
        }
        
        int mid = lo + (hi-lo)/2;
        int prev = (mid-1+n)%n;
        int next = (mid+1)%n;
        
        if(nums[mid]<=nums[prev] and nums[mid]<=nums[next]) {
            return nums[mid];
        }
        
        if(nums[lo]<=nums[mid]) {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return -1;
}
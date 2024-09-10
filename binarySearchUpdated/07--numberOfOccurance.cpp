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
int count(vector<int>& arr, int n, int x) {
	int lower = lowerBound(arr, x);
	if(lower==n) return 0;
	else if(arr[lower]!=x) return 0;
	int upper = upperBound(arr, x);
	return (upper-lower);
}

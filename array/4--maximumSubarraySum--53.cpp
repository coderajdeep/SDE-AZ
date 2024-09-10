// leetcode 53
// Maximum subarray sum - Kadane's Algorithm
// Time complexity O(n)
// Space complexity O(1)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    // This is for tracking ovarall maximum value
    int maxVal = nums[0];
    // This is for tracking current maximum value
    int val = nums[0];
    for(int i=1; i<n; ++i) {
        // If the current number is greater than 
        // the value of current number + currentActive subarray
        if(nums[i]<(nums[i]+val)) {
            val += nums[i];
        }
        else {
            val = nums[i];
        }
        if(maxVal<val) {
            maxVal = val;
        }
    }
    return maxVal;
}
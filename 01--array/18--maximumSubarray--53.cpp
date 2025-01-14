// Maximum subarray sum - Kadane's Algorithm -- leetcode 53

// Time complexity O(n)
// Space complexity O(1)
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    // This is for tracking ovarall maximum value
    int maxSumValue = INT_MIN;
    // This is for tracking current maximum value
    int currMax = 0;
    for(int i=0; i<n; ++i) {
        // This is to check if I can include the currentElement in the currMax or not
        if(nums[i]<(nums[i]+currMax)) {
            currMax += nums[i];
        }
        else {
            currMax = nums[i];
        }
        // Update the maxSumValue
        if(maxSumValue<currMax) {
            maxSumValue = currMax;
        }
    }
    return maxSumValue;
}

// Question can be length of the max or min subarray
// Below solution is for max length
// If the question is about getting the subarray itself then the solution will be
pair<int, int> maxSubArray(vector<int>& nums) {
    int n = nums.size();
    // This is for tracking ovarall maximum value
    int maxSumValue = INT_MIN;
    // This is for tracking current maximum value
    int currMax = 0;
    int start, low, high;
    for(int i=0; i<n; ++i) {
        // If the current number is greater than 
        // the value of current number + currentActive subarray
        // Then I will update the current maximum
        if(nums[i]<(nums[i]+currMax)) {
            currMax += nums[i];
        }
        else {
            currMax = nums[i];
            start = index;
        }
        if(maxSumValue<currMax) {
            low = start;
            high = index;
            maxSumValue = currMax;
        }
    }
    // this is not true
    // this will return the one of the subarray
    return pair<int, int> {low, high};
}
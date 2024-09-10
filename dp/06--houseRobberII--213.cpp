// House Robber II -- leetcode 213

// Space optimized tabulation
// Time complexity O(n)
// Space complexity O(1)
int getMaxAmount(int start, int end, vector<int> &nums) {
    if(start == end) return nums[start];
    if((start + 1) == end) return max(nums[start], nums[end]);
    int prev2 = nums[start];
    int prev = max(nums[start], nums[start+1]);
    for(int i=start+2; i<=end; ++i) {
        int curr = max(prev, prev2+nums[i]);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int firstCase = getMaxAmount(0, n-2, nums);
    int secondCase = getMaxAmount(1, n-1, nums);
    return max(firstCase, secondCase);
}

// Tabulation
// Bottom Up
// Time complexity O(n)
// Space complexity O(n)
// This is index specific
int getMaxAmount(int start, int end, vector<int> &nums) {
    vector<int> dp(end+1);
    dp[start] = nums[start];
    if(end == start) return dp[end];

    dp[start + 1] = max(nums[start], nums[start + 1]);
    if(end == (start+1)) return dp[end];

    for(int i = (start + 2); i <= end; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[end];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    int firstCase = getMaxAmount(0, n-2, nums);
    int secondCase = getMaxAmount(1, n-1, nums);
    return max(firstCase, secondCase);
}


// Memoization
// Top down
// Time complexity O(n)
// Space complexity O(n) + Recursion Stack Space O(n)
int getMaxAmount(int start, int end, vector<int> &nums, vector<int> &dp) {
    // base case
    if(start == end) return nums[start];
    if((start+1) == end) return max(nums[start], nums[start+1]);
    
    if(dp[end] != -1) return dp[end];

    int pickedCurrent = nums[end] + getMaxAmount(start, end-2, nums, dp);
    int notPickedCurrent = getMaxAmount(start, end-1, nums, dp);

    return dp[end] = max(pickedCurrent, notPickedCurrent);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    // edge case
    if(n == 1) return nums[0];
    vector<int> dp1(n, -1), dp2(n, -1);
    int firstCase = getMaxAmount(0, n-2, nums, dp1);
    int secondCase = getMaxAmount(1, n-1, nums, dp2);
    return max(firstCase, secondCase);
}
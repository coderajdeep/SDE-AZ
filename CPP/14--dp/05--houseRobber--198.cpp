// House Robber -- leetcode 198

// Best approach
// Space optimized
// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(1)
int rob(vector<int>& nums) {
    int n = nums.size();
    int prev2 = nums[0];
    if(n==1) return prev2;
    int prev = max(nums[0], nums[1]);
    if(n==2) return prev;
    int curr;
    for(int index=2; index<n; ++index) {
        int pick = prev2 + nums[index];
        int notPick = prev;
        curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(n)
int rob(vector<int>& nums) {
    int n = nums.size();
    int dp[n];
    dp[0] = nums[0];
    if(n==1) return dp[0];
    dp[1] = max(nums[0], nums[1]);
    if(n==2) return dp[1];
    for(int index=2; index<n; ++index) {
        int pick = dp[index-2] + nums[index];
        int notPick = dp[index-1];
        dp[index] = max(pick, notPick);
    }
    return dp[n-1];
}

// Memoization - top down approach
// Time complexity O(n)
// Space complexity O(2n)
// Considering recursion stack space
int solve(int index, vector<int> &nums, vector<int> &dp) {
    if(index==0) {
        return nums[0];
    }
    if(index==1) {
        return max(nums[0], nums[1]);
    }
    if(dp[index]!=-1) {
        return dp[index];
    }
    int pick = solve(index-2, nums, dp) + nums[index];
    int notPick = solve(index-1, nums, dp);
    return dp[index] = max(pick, notPick);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solve(n-1, nums, dp);
    return ans;
}
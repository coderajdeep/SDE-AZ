// Max Coins for burst balloons -- leetcode 312
// Time complexity O(n*n*n)
// Space complexity O(n*n) + O(n) Recursion Stack space
int getMax(int start, int end, vector<int> &nums, vector<vector<int>> &dp) {
    if(start>end) return 0;
    if(dp[start][end] != -1) return dp[start][end];
    int maxCoins = INT_MIN;
    for(int index=start; index<=end; ++index) {
        int leftPartition = getMax(start, index-1, nums, dp);
        int rightPartition = getMax(index+1, end, nums, dp);
        int currCost = nums[start-1] * nums[index] * nums[end+1];
        int totalCost = leftPartition + currCost + rightPartition;
        maxCoins = max(maxCoins, totalCost);
    }
    return dp[start][end] = maxCoins;
}
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n-1, vector<int>(n-1, -1));
    return getMax(1, n-2, nums, dp);
}
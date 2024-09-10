// Find Number of LIS -- leetcode 673
// Time complexity O(n*n)
// Space complexity O(n)

// [2, 2, 2]
// [1,2,4,3,5,4,7,2]
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), count(n, 1);
    int maxLen = 1;
    for(int curr=1; curr<n; ++curr) {
        for(int prev=0; prev<curr; ++prev) {
            if(nums[prev]<nums[curr] && (dp[prev]+1>dp[curr])) {
                dp[curr] = 1 + dp[prev];
                count[curr] = count[prev];
            }
            else if(nums[prev]<nums[curr] && (dp[prev]+1==dp[curr])) {
                count[curr] += count[prev];
            }
        }
        if(maxLen < dp[curr]) maxLen = dp[curr];
    }
    int ans = 0;
    for(int i=0; i<n; ++i) {
        if(dp[i]==maxLen) {
            ans += count[i];
        }
    }
    return ans;
}
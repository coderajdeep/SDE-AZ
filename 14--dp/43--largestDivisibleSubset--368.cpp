// Largest Divisible subset -- leetcode 368
// Time complexity O(n*n)
// Space complexity O(n)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    int hash[n];
    int dp[n];
    dp[0] = 1;
    hash[0] = 0;
    sort(nums.begin(), nums.end());
    int maxLen = 1, maxLenIndex = 0;
    for(int i=1; i<n; ++i) {
        dp[i] = 1;
        hash[i] = i;
        for(int j=0; j<i; ++j) {
            if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1) {
                dp[i] = dp[j] + 1;
                hash[i] = j;
                if(maxLen < dp[i]) {
                    maxLen = dp[i];
                    maxLenIndex = i;
                }
            }
        }
    }
    int prev = maxLenIndex;
    vector<int> ans(maxLen);
    for(int i=maxLen-1; i>=0; --i) {
        ans[i] = nums[prev];
        prev = hash[prev];
    }
    return ans;
}
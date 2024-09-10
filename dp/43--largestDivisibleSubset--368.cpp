// Largest Divisible subset -- leetcode 368
// Time complexity O(n*n)
// Space complexity O(n)
vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int dp[n];
    int hash[n];
    for(int i=0; i<n; ++i) {
        dp[i] = 1;
        hash[i] = i;
    }

    int len = 1, maxIndex = 0;
    for(int curr=1; curr<n; ++curr) {
        for(int prev=0; prev<curr; ++prev) {
            if((nums[curr]%nums[prev]==0) && (dp[prev]+1>dp[curr])) {
                dp[curr] = dp[prev] + 1;
                hash[curr] = prev;
            }
        }
        if(len < dp[curr]) {
            len = dp[curr];
            maxIndex = curr;
        }
    }

    vector<int> ans(len);
    for(int i=len-1; i>=0; --i) {
        ans[i] = nums[maxIndex];
        maxIndex = hash[maxIndex];
    }
    return ans;
}
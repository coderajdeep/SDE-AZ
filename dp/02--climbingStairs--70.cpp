// Climbing Stairs -- leetcode 70

// Best approach
// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(1)
int climbStairs(int n) {
    if(n<=2) return n;
    int prev2 = 1, prev = 2, curr;
    for(int i=3; i<=n; ++i) {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(n)
int climbStairs(int n) {
    if(n<=2) return n;
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Memoization - top down approach
// Time complexity O(n)
// Space complexity O(2n)
// Considering recursion stack space
int solve(int n, vector<int>& dp) {
    if(n<=2) return n;
    if(dp[n]!=-1) {
        return dp[n];
    }
    int prev2 = solve(n-2, dp);
    int prev = solve(n-1, dp);
    dp[n] = prev + prev2;
    return dp[n];
}
int climbStairs(int n) {
    if(n<=2) return n;
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    return ans;
}
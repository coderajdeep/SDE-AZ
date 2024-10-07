// N-th fibonacci number

// Memoization - top down approach
// Time complexity O(n)
// Space complexity O(2n)
// Considering recursion stack space
int solve(int n, vector<int> &dp) {
    if(n<=2) return 1;
    if(dp[n]!=-1) {
        return dp[n];
    }
    int mod = 1e9+7;
    dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % mod;
    return dp[n];
}
int nthFibonacci(int n){
    if(n<=2) return 1;
    vector<int> dp(n+1, -1);
    int ans = solve(n, dp);
    return ans;
}


// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(n)
int nthFibonacci(int n){
    if(n<=2) return 1;
    vector<int> dp(n+1, 1);
    const int mod = 1e9+7;
    for(int i=3; i<=n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    return dp[n];
}

// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(1)
int nthFibonacci(int n){
    if(n<=2) return 1;
    const int mod = 1e9+7;
    int prev2 = 1, prev = 1, curr;
    for(int i=3; i<=n; ++i) {
        curr = (prev2 + prev) % mod;
        prev2 = prev;
        prev =
    }
    return dp[n];
}
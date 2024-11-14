// Memoization
// Time complexity O(n*n)
// Space complexity O(n*n) + Recursion stack space 0(n)
int solve(int index, int len, int *price, vector<vector<int>> &dp) {
    if(len==0) return 0;
    if(index==0) return price[0] * len;
    if(dp[index][len] != -1) return dp[index][len];
    int take = ((index+1)<=len) ? price[index] + solve(index, len-index-1, price, dp) : 0;
    int notTake = solve(index-1, len, price, dp);
    return dp[index][len] = max(take, notTake);
}
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(n-1, n, price, dp);
}

// Tabulation
// Time complexity O(n*n)
// Space complexity O(n*n)
int cutRod(int price[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1));
    for(int i=0; i<n; ++i) {
        dp[i][0] = 0;
        for(int j=1; j<=n; ++j) {
            if(i==0) {
                dp[i][j] = (j*price[0]);
            }
            else {
                int take = ((i+1)<=j) ? dp[i][j-i-1] + price[i] : 0;
                int notTake = dp[i-1][j];
                dp[i][j] = max(take, notTake);
            }
        }
    }
    return dp[n-1][n];
}


// Space optimized
// Uisng only one 1D array
// Time complexity O(n*n)
// Space complexity O(n)
int cutRod(int price[], int n) {
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i=0; i<n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(i==0) {
                dp[j] = (j*price[0]);
            }
            else {
                int take = ((i+1)<=j) ? dp[j-i-1] + price[i] : 0;
                int notTake = dp[j];
                dp[j] = max(take, notTake);
            }
        }
    }
    return dp[n];
}
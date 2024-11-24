// leetcode 62
// Unique Paths
// Memoization - top down approach
// Time complexity O(m*n)
// Space complexity O(m*n)
int solve(int r, int c, int row, int col, vector<vector<int>>& dp) {
    if(r<0) return 0;
    if(c<0) return 0;
    if(r==0 || c==0) return 1;
    if(dp[r][c]!=-1) return dp[r][c];
    int up = solve(r-1, c, row, col, dp);
    int left = solve(r, c-1, row, col, dp);
    return dp[r][c] = (up + left);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = solve(m-1, n-1, m, n, dp);
    return ans;
}

// Tabulation or bottom up
// Time complexity O(m*n)
// Space complexity O(m*n)
int uniquePaths(int m, int n) {
    int dp[m][n];
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0 || j==0) {
                dp[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

// Space optimized tabulation or bottom up
// Time complexity O(m*n)
// Space complexity O(n)
int uniquePaths(int m, int n) {
    int prev[n], curr[n];
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(i==0 || j==0) {
                curr[j] = 1;
            }
            else {
                curr[j] = curr[j-1] + prev[j];
            }
        }
        for(int k=0; k<n; ++k) {
            prev[k] = curr[k];
        }
    }
    return curr[n-1];
}
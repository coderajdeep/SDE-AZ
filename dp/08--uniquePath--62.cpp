// Unique path - leetcode 62

// Best approach
// Space optimized 
// Time complexity O(n*m)
// Space complexity O(n)
// Using only one array
int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for(int i=1; i<m; ++i) {
        for(int j=1; j<n; ++j) {
            // left : dp[j-1]
            // up : dp[j]
            dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}

// Updated base condition
// Top down
// Memoization
// Time complexity O(n * m)
// Space complexity O(n * m) + Recursion Stack Space O(n + m)
int solve(int i, int j, vector<vector<int>> &dp) {
    if(i==0 || j==0) {
        return 1;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = solve(i, j-1, dp) + solve(i-1, j, dp);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solve(m-1, n-1, dp);
}

// Top down
// Memoization
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion Stack Space O(n+m)
int uniquePathUtils(int r, int c, vector<vector<int>> &dp) {
    if(r==0 && c==0) return 1;
    if(r<0 || c<0) return 0;
    if(dp[r][c] != -1) return dp[r][c];
    int left = uniquePathUtils(r, c-1, dp);
    int up = uniquePathUtils(r-1, c, dp);
    return dp[r][c] = (left + up);
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return uniquePathUtils(m-1, n-1, dp);
}

// Bottom up
// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m)
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            // left -> dp[i][j-1]
            // up -> dp[i-1][j]
            if(i==0 || j==0) dp[i][j] = 1;
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}

// Space optimized
// Best solution
// Time complexity O(n*m)
// Space complexity O(n)
int uniquePaths(int m, int n) {
    vector<int> prev(n, 1), curr(n, 1);
    for(int i=1; i<m; ++i) {
        for(int j=1; j<n; ++j) {
            // left curr[j-1]
            // up prev[j]
            curr[j] = curr[j-1] + prev[j];
        }
        for(int j=1; j<n; ++j) {
            prev[j] = curr[j];
        }
    }
    return prev[n-1];
}
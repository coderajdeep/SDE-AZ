// Minimum Path Sum -- leetcode 64

// Memoization
// Top down approach
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion Stack Space O(n*m)
int minPath(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    if(r==0 && c==0) return grid[0][0];
    if(r<0 || c<0) return INT_MAX;
    if(dp[r][c] != -1) return dp[r][c];
    int left = minPath(r, c-1, grid, dp);
    int up = minPath(r-1, c, grid, dp);
    return dp[r][c] = min(left, up) + grid[r][c];
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return minPath(n-1, m-1, grid, dp);
}

// Tabulation
// Bottom Up approach
// Time complexity O(n*m)
// Space complexity O(n*m)
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else {
                int left = (j>0) ? dp[i][j-1] : INT_MAX;
                int up = (i>0) ? dp[i-1][j] : INT_MAX;
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }
    }
    return dp[n-1][m-1];
}

// Best Approach
// Space optimized
// Time complexity O(n*m)
// Space complexity O(m)
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> curr(m);

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i==0 && j==0) curr[j] = grid[i][j];
            else {
                int up = (i>0) ? curr[j] : INT_MAX;
                int left = (j>0) ? curr[j-1] : INT_MAX;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
    }
    return curr[m-1];
}
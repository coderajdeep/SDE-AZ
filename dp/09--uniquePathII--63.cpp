// Unique Path II -- leetcode 63

// Best approach
// Space optimized approach
// Time complexity O(n*m)
// Space complexity O(m) : Only single array used
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> dp(m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(obstacleGrid[i][j]==1) {
                dp[j] = 0;
            }
            else if(i==0 && j==0) {
                dp[0] = 1;
            }
            else {
                int left = j>0 ? dp[j-1] : 0;
                int right = i>0 ? dp[j] : 0;
                dp[j] = left + right;
            }
        }
    }
    return dp[m-1];
}

// Memoization
// Top down
// Time complexity O(n*m)
// Space complexity O(n * m) + recursion stack space O(n + m)
int uniquePathUtils(int r, int c, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
    if(r<0 || c<0) return 0;
    if(obstacleGrid[r][c]==1) return 0;
    if(r==0 && c==0) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    int left = uniquePathUtils(r, c-1, obstacleGrid, dp);
    int up = uniquePathUtils(r-1, c, obstacleGrid, dp);
    return dp[r][c] = (left + up);
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return uniquePathUtils(n-1, m-1, obstacleGrid, dp);
}

// Tabulation
// Bottom Up
// Time complexity O(n*m)
// Space complexity O(n*m)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(obstacleGrid[i][j]==1) dp[i][j] = 0;
            else if(i==0 && j==0) dp[i][j] = 1;
            else {
                int up = i>0 ? dp[i-1][j] : 0;
                int left = j>0 ? dp[i][j-1] : 0;
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n-1][m-1];
}

// best approach
// Space optimized
// Time complexity O(n*m)
// Space complexity O(m)
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> prev(m), curr(m);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(obstacleGrid[i][j]==1) curr[j] = 0;
            else if(i==0 && j==0) curr[j] = 1;
            else {
                int up = i>0 ? prev[j] : 0;
                int left = j>0 ? curr[j-1] : 0;
                curr[j] = up + left;
            }
        }
        for(int j=0; j<m; ++j) prev[j] = curr[j];
    }
    return curr[m-1];
}
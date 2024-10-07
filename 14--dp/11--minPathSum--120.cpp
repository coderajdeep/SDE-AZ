// Minimum path sum in triangle -- leetcode 120
// This problem can be solved from top to bottom or bottom to top
// But top to bottom will be much simpler because here starting point will be fixed

// Best approach
// Space optimized
// Time complexity O(n*n)
// Space complexity O(n)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> dp(n);
    for(int i=n-1; i>=0; --i) {
        for(int j=0; j<=i; ++j) {
            if(i==n-1) dp[j] = triangle[i][j];
            else {
                int down = dp[j];
                int right = dp[j+1];
                dp[j] = triangle[i][j] + min(down, right);
            }
        }
    }
    return dp[0];
}

// Top Down
// Memoization
// Time complexity O(n*n)
// Space complexity O(n*n) + Recursion stack space O(n)
int getMinTotal(int i, int j, int rowIndex, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
    if(i==rowIndex) return triangle[i][j];
    if(dp[i][j] != -1) return dp[i][j];
    int down = getMinTotal(i+1, j, rowIndex, triangle, dp);
    int right = getMinTotal(i+1, j+1, rowIndex, triangle, dp);
    return dp[i][j] = (triangle[i][j] + min(down, right));
}
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return getMinTotal(0, 0, n-1, triangle, dp);
}

// Bottom Up
// Tabulation
// Time complexity O(n*n)
// Space complexity O(n)
int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for(int i=n-1; i>=0; --i) {
        for(int j=0; j<=i; ++j) {
            if(i==n-1) dp[i][j] = triangle[i][j];
            else {
                int down = dp[i+1][j];
                int right = dp[i+1][j+1];
                dp[i][j] = triangle[i][j] + min(down, right);
            }
        }
    }
    return dp[0][0];
}
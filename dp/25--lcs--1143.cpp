// Longest Common Subsequence -- 1143

// Memoization
// Time complexity O(n*m)
// Space complexity O(n*m)
int lcs(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
    if(n==0 || m==0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s1[n-1] == s2[m-1]) return dp[n][m] = (1 + lcs(n-1, m-1, s1, s2, dp));
    int up = lcs(n-1, m, s1, s2, dp);
    int left = lcs(n, m-1, s1, s2, dp);
    return dp[n][m] = max(up, left);
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return lcs(n, m, text1, text2, dp);
}

// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m)
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // for every i==0 or j==0, ans will be zero
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            // up = dp[i-1][j]
            // left = dp[i][j-1]
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}


// Space optimized
// Time complexity O(n*m)
// Space complexity O(m)
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m+1, 0), curr(m+1);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
            // up = prev[j]
            // left = curr[j-1]
            else curr[j] = max(prev[j], curr[j-1]);
        }
        for(int j=1; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
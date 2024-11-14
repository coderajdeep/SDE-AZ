// Edit distance -- leetcode 72

// Time complexity O(n*m)
// Space complexity O(n*m) + O(n+m) recursion stack space
int editDistance(int n, int m, string &s1, string &s2, vector<vector<int>> &dp) {
    if(n==0 && m==0) return 0;
    if(n==0 || m==0) return max(n, m);
    if(dp[n][m] != -1) return dp[n][m];
    if(s1[n-1] == s2[m-1]) return dp[n][m] = editDistance(n-1, m-1, s1, s2, dp);
    int insertStr = editDistance(n, m-1, s1, s2, dp);
    int replaceStr = editDistance(n-1, m-1, s1, s2, dp);
    int deleteStr = editDistance(n-1, m, s1, s2, dp);
    return dp[n][m] = (1 + min({insertStr, replaceStr, deleteStr}));
}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return editDistance(n, m, word1, word2, dp);
}


// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m)
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=0; i<=n; ++i) dp[i][0] = i;
    for(int i=1; i<=m; ++i) dp[0][i] = i;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                int insertStr = dp[i][j-1];
                int replaceStr = dp[i-1][j-1];
                int deleteStr = dp[i-1][j];
                dp[i][j] = 1 + min({insertStr, replaceStr, deleteStr});
            }
        }
    }
    return dp[n][m];
}

// Space optimized
// Edit distance
// Time complexity O(n*m)
// Space complexity O(m)
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<int> prev(m+1), curr(m+1);
    for(int i=0; i<=m; ++i) prev[i] = i; // here we need to insert
    for(int i=1; i<=n; ++i) {
        // here we need to delete
        curr[0] = i;
        for(int j=1; j<=m; ++j) {
            if(word1[i-1]==word2[j-1]) curr[j] = prev[j-1];
            else {
                int insertStr = curr[j-1];
                int replaceStr = prev[j-1];
                int deleteStr = prev[j];
                curr[j] = 1 + min({insertStr, replaceStr, deleteStr});
            }
        }
        for(int j=0; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
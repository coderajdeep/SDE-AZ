// Minimum delete operation to convert one string to another -- leetcode 583
// Memoization
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion stack space O(n*m)
int getMinDist(int n, int m, string &word1, string &word2, vector<vector<int>> &dp) {
    if(n==0 && m==0) return 0;
    if(n==0 || m==0) return (n<m)? m : n;
    if(dp[n][m] != -1) return dp[n][m];
    if(word1[n-1]==word2[m-1]) return dp[n][m] = getMinDist(n-1, m-1, word1, word2, dp);
    int firstDelete = 1 + getMinDist(n-1, m, word1, word2, dp);
    int secondDelete = 1 + getMinDist(n, m-1, word1, word2, dp);
    return dp[n][m] = min(firstDelete, secondDelete);
}
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return getMinDist(n, m, word1, word2, dp);
}


// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m)
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<=n; ++i) {
        for(int j=0; j<=m; ++j) {
            if(i==0 && j==0) dp[0][0] = 0;
            else if(i==0) dp[i][j] = j;
            else if(j==0) dp[i][j] = i;
            else if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[n][m];
}

// Space optimized
// Time complexity O(n*m)
// Space complexity O(m)
int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<int> prev(m+1), curr(m+1);
    prev[0] = 0;
    for(int i=1; i<=m; ++i) prev[i] = i;
    for(int i=1; i<=n; ++i) {
        curr[0] = i;
        for(int j=1; j<=m; ++j) {
            if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1 + min(curr[j-1], prev[j]);
        }
        for(int j=0; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
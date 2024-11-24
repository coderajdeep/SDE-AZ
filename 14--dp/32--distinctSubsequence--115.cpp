// Distinct Subsequence -- leetcode 115

// Memoization
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion stack space O(n+m)
int distSubUtils(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
    if(m==0) return 1;
    if(n==0) return 0;
    if(dp[n][m] != -1) return dp[n][m];
    if(s[n-1]==t[m-1]) {
        int match = distSubUtils(n-1, m-1, s, t, dp);
        int notMatch = distSubUtils(n-1, m, s, t, dp);
        return dp[n][m] = (match + notMatch);
    }
    return dp[n][m] = distSubUtils(n-1, m, s, t, dp);
}
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return distSubUtils(n, m, s, t, dp);
}

// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion stack space O(n+m)
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    const int mod = 1e9+7;
    long long dp[n+1][m+1];
    for(int i=0; i<=n; ++i) dp[i][0] = 1;
    for(int i=1; i<=m; ++i) dp[0][i] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i-1]==t[j-1]) {
                long long pick = dp[i-1][j-1];
                long long notPick = dp[i-1][j];
                dp[i][j] = (pick + notPick)%mod;
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

// Space optimized
// Time complexity O(n*m)
// Space complexity O(m)
int numDistinct(string s, string t) {
    int n = s.size();
    int m = t.size();
    const int mod = 1e9+7;
    vector<long long> prev(m+1), curr(m+1);
    prev[0] = 1;
    for(int i=1; i<=m; ++i) prev[i] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i-1] == t[j-1]) {
                long long pick = prev[j-1];
                long long notPick = prev[j];
                curr[j] = (pick + notPick) % mod;
            }
            else {
                // not able to pick
                curr[j] = prev[j];
            }
        }
        for(int j=1; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
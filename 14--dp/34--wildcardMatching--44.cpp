// Wild Card Matching -- leetcode 44
// Time complexity O(n*m)
// Space complexity O(n*m) + Recursion Stack Space (n+m )
int isMatchUtils(int n, int m, string &s, string &p, vector<vector<int>> &dp) {
    if(n==0 && m==0) return 1;
    if(m==0) return 0;
    if(n==0) {
        for(int i=0; i<m; ++i) {
            if(p[i]!='*') return 0;
        }
        return 1;
    }
    if(dp[n][m] != -1) return dp[n][m];
    if(s[n-1]==p[m-1] || p[m-1]=='?') {
        return dp[n][m] = isMatchUtils(n-1, m-1, s, p, dp);
    }
    if(p[m-1]=='*') {
        bool matchEmptyStr = isMatchUtils(n, m-1, s, p, dp);
        bool matchNonEmptyStr = isMatchUtils(n-1, m, s, p, dp);
        return dp[n][m] = (matchEmptyStr || matchNonEmptyStr);
    }
    return 0;
}
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    return (isMatchUtils(n, m, s, p, dp) == 1);
}


// Tabulation
// Time complexity O(n*m)
// Space complexity O(n*m)
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1));
    dp[0][0] = true;
    for(int i=1; i<=m; ++i) {
        dp[0][i] = (p[i-1]=='*' && dp[0][i-1]);
    }
    for(int i=1; i<=n; ++i) {
        dp[i][0] = false;
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i-1]==p[j-1] || p[j-1]=='?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1]=='*') {
                dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
            }
            else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}


// Space Optimized
// Time complexity O(n*m)
// Space complexity O(m)
bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<bool> prev(m+1), curr(m+1);
    prev[0] = true;
    curr[0] = false;
    for(int i=1; i<=m; ++i) {
        prev[i] = prev[i-1] && (p[i-1]=='*');
    }
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(s[i-1]==p[j-1] || p[j-1]=='?') {
                curr[j] = prev[j-1];
            }
            else if(p[j-1]=='*') {
                curr[j] = (prev[j] || curr[j-1]);
            }
            else {
                curr[j] = false;
            }
        }
        for(int j=0; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
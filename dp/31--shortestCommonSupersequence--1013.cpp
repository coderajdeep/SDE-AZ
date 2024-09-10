// Shortest common supersequence -- leetcode 1092
// Time complexity O(n*m)
// Space complexity O(n*m) + O(n+m)
string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for(int i=0; i<=n; ++i) dp[i][0] = 0;
    for(int i=0; i<=m; ++i) dp[0][i] = 0;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    int len = n + m - dp[n][m];
    string str(len, '#');
    int i=n, j=m, index=(len-1);
    while(i>0 && j>0 && index>=0) {
        if(str1[i-1]==str2[j-1]) {
            str[index] = str1[i-1];
            index = index - 1;
            i = i - 1;
            j = j - 1;
        }
        else {
            if(dp[i][j-1] < dp[i-1][j]) {
                str[index] = str1[i-1];
                index = index - 1;
                i = i - 1;
            }
            else {
                str[index] = str2[j-1];
                index = index - 1;
                j = j - 1;
            }
        }
    }
    while(i>0) {
        str[index] = str1[i-1];
        --index;
        --i;
    }
    while(j>0) {
        str[index] = str2[j-1];
        --index;
        --j;
    }
    return str;
}
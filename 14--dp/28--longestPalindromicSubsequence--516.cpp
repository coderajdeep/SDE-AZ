// Longest Palindromic Subsequence -- leetcode 516
// Time complexity O(n*m)
// Space complexity O(m)
int longestCommonSubsequence(string &text1, string &text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(text1[i-1]==text2[j-1]) curr[j] = 1 + prev[j-1];
            else curr[j] = max(prev[j], curr[j-1]);
        }
        for(int j=1; j<=m; ++j) prev[j] = curr[j];
    }
    return prev[m];
}
int longestPalindromeSubseq(string s) {
    string s2(s);
    reverse(s2.begin(), s2.end());
    return longestCommonSubsequence(s, s2);
}

// Longest palindromic substring
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // string starts from j and end in i index
        int maxLen = 0, start = 0;
        for(int i=0; i<n; ++i) {
            for(int j=i; j>=0; --j) {
                if(j==i) dp[j][i] = true;
                else if(j+1==i) dp[j][i] = (s[j]==s[i]);
                else {
                    dp[j][i] = (s[j]==s[i] && dp[j+1][i-1]);
                }
                if(dp[j][i] && maxLen < (i-j+1)) {
                    maxLen = (i-j+1);
                    start = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
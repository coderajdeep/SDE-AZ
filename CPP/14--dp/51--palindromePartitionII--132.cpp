// Palindrome Partitioning II -- leetcode 132
// Time complexity O(n*n)
// Space complexity O(n) + Recursion stack space O(n)
bool isPalindrom(int start, int end, string &str) {
    while(start<end) {
        if(str[start++]!=str[end--]) {
            return false;
        }
    }
    return true;
}
int getMinCuts(int start, int end, string &str, vector<int> &dp) {
    if(start>end) return 0;
    if(dp[start] != -1) return dp[start];
    int minCut = INT_MAX;
    for(int index=start; index<=end; ++index) {
        bool isPal = isPalindrom(start, index, str);
        if(isPal) {
            minCut = min(minCut, 1 + getMinCuts(index+1, end, str, dp));
        }
    }
    return dp[start] = minCut;
}
int minCut(string s) {
    int n = s.size();
    vector<int> dp(n, -1);
    int ans = getMinCuts(0, n-1, s, dp) - 1;
    return ans;
}
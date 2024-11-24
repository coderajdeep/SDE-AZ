// Time complexity O(n)
// Space complexity O(n)
int distSubsequence(string &str) {
    int n = str.size();
    unordered_map<char, long long> umap;
    long long dp[n];
    dp[0] = 1;
    for(int i=1; i<=n; ++i) {
        dp[i] = (dp[i-1]*2);
        auto it = umap.find(str[i-1]);
        if(it != umap.end()) {
            dp[i] = (dp[i] - it->second);
        }
        umap[str[i-1]] = dp[i-1];
    }
    return dp[n]-1;
}
string betterString(string str1, string str2) {
    return distSubsequence(str1) >= distSubsequence(str2) ? str1 : str2;
}
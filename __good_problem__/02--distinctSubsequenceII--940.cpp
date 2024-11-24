// Time complexity O(n)
// Space complexity O(1)

int distinctSubseqII(string s) {
    unordered_map<char, long long> prev;
    int n = s.size();
    const int mod = 1e9+7;
    // dp[n] --> total distinct subsequence including empty subsequence
    vector<long long> dp(n+1);
    dp[0] = 1; // if the length is zero then there will be one empty subsequence
    for(int i=1; i<=n; ++i) {
        char ch = s[i-1];
        dp[i] = (2 * dp[i-1]) % mod;
        if(prev.find(ch) != prev.end()) {
            dp[i] = (dp[i] - prev[ch] + mod) % mod;
        }
        prev[ch] = dp[i-1];
    }
    return (int)((dp[n] - 1 + mod) % mod);
}
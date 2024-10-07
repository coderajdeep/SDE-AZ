// Minimum Cost to Cut a stick -- leetcode 1547
// Memoization
// Time complexity O(N*N*N)
// Space complexity O(N*N) + Recursion stack Space O(N)
int getMinCost(int start, int end, vector<int> &cuts, vector<vector<int>> &dp) {
    if(start>end) return 0;
    if(dp[start][end] != -1) return dp[start][end];
    int minCost = INT_MAX;
    for(int index=start; index<=end; ++index) {
        int firstPartition = getMinCost(start, index-1, cuts, dp);
        int secondPartition = getMinCost(index+1, end, cuts, dp);
        int totalCost = (cuts[end+1] - cuts[start-1]) + firstPartition + secondPartition;
        minCost = min(minCost, totalCost);
    }
    return dp[start][end] = minCost;
}
int minCost(int n, vector<int>& cuts) {
    sort(cuts.begin(), cuts.end());
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    int N = cuts.size();
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return getMinCost(1, N-2, cuts, dp);
}
// Memoization
// Time complexity O(n*amount)
// Space complexity O(n*amount) + recursive stack space O(n)
int solve(int index, int amount, vector<int> &coins, vector<vector<int>> &dp) {
    // if we do not include this condition then also the generic condition will handle this
    if(amount==0) return 1;
    if(index==0) {
        if(amount % coins[0] == 0) return 1;
        else return 0;
    }
    if(dp[index][amount] != -1) return dp[index][amount];
    int includeCount = (coins[index]<=amount) ? solve(index, amount-coins[index], coins, dp) : 0;
    int notIncludeCount = solve(index-1, amount, coins, dp);
    return dp[index][amount] = (includeCount + notIncludeCount);
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    return solve(n-1, amount, coins, dp);
}


// Tabulation
// Time complexity O(n*amount)
// Space complexity O(n*amount) + recursive stack space O(n)
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1));
    for(int i=0; i<n; ++i) {
        dp[i][0] = 1;
        for(int j=1; j<=amount; ++j) {
            if(i==0) {
                if(j % coins[0] == 0) dp[i][j] = 1;
                else dp[i][j] = 0;
            }
            else {
                int includeCount = (coins[i]<=j) ? dp[i][j-coins[i]] : 0;
                int notIncludeCount = dp[i-1][j];
                dp[i][j] = (includeCount + notIncludeCount);
            }
        }
    }
    return dp[n-1][amount];
}

// Space optimized tabulation
// Time complexity O(n*amount)
// Space complexity O(n*amount) + recursive stack space O(n)
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<int> dp(amount+1);
    dp[0] = 1;
    for(int i=0; i<n; ++i) {
        for(int j=1; j<=amount; ++j) {
            if(i==0) {
                if(j % coins[0] == 0) dp[j] = 1;
                else dp[j] = 0;
            }
            else {
                int includeCount = (coins[i]<=j) ? dp[j-coins[i]] : 0;
                int notIncludeCount = dp[j];
                dp[j] = (includeCount + notIncludeCount);
            }
        }
    }
    return dp[amount];
}
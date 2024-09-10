// Best time to buy and sell stocks II -- leetcode 122
// Unlimited transaction
// But can hold only one stock
// Most optimized way
// Time complexity O(n)
// Space complexity O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxProfit = 0;
    for(int i=1; i<n; ++i) {
        if(prices[i-1]<prices[i]) {
            maxProfit += (prices[i] - prices[i-1]);
        }
    }
    return maxProfit;
}

// Time complexity O(2*n)
// Space complexity O(2*n) + O(n+2) Recursion stack space
int getMaxProfit(int dayIndex, int buyPossible, vector<int>& prices, vector<vector<int>> &dp) {
    if(dayIndex==prices.size()) {
        return 0;
    }

    if(dp[dayIndex][buyPossible] != -1) return dp[dayIndex][buyPossible];

    int profit = INT_MIN;
    if(buyPossible) {
        int buy = getMaxProfit(dayIndex+1, 0, prices, dp) - prices[dayIndex];
        int notBuy = getMaxProfit(dayIndex+1, 1, prices, dp);
        profit = max(buy, notBuy);
    }
    else {
        int sell = getMaxProfit(dayIndex+1, 1, prices, dp) + prices[dayIndex];
        int notSell = getMaxProfit(dayIndex+1, 0, prices, dp);
        profit = max(sell, notSell);
    }
    return dp[dayIndex][buyPossible] = profit;
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2, -1)); 
    return getMaxProfit(0, true, prices, dp);
    // return dp[0][1]
}

// Tabulation
// Time complexity O(n*2)
// Space complexity O(n*2)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2));
    dp[n][0] = dp[n][1] = 0;
    for(int i=n-1; i>=0; --i) {
        // buy possible
        // buy
        int buy = dp[i+1][0] - prices[i];
        // not buy
        int notBuy = dp[i+1][1];
        dp[i][1] = max(buy, notBuy);

        // buy not possible
        // sell
        int sell = dp[i+1][1] + prices[i];
        // not sell
        int notSell = dp[i+1][0];
        dp[i][0] = max(sell, notSell);
    }
    return dp[0][1];
}
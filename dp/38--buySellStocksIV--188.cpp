// Best time to buy and sell stocks IV -- leetcode 188

// Memoization
// Time complexity O(n*k*2) 
// Space complexity O(n*k*2) + Recursion stack space O(n+k)
int getMaxProfit(int day, int limit, int buyFlag, vector<int>& prices, vector<vector<vector<int>>> &dp) {
    if(day==prices.size() || limit==0) return 0;
    if(dp[day][limit][buyFlag] != -1) return dp[day][limit][buyFlag];
    int buyMax = INT_MIN, sellMax = INT_MIN;
    if(buyFlag==1) {
        int buy = getMaxProfit(day+1, limit, 0, prices, dp) - prices[day];
        int notBuy = getMaxProfit(day+1, limit, 1, prices, dp);
        buyMax = max(buy, notBuy);
    }
    else {
        int sell = getMaxProfit(day+1, limit-1, 1, prices, dp) + prices[day];
        int notSell = getMaxProfit(day+1, limit, 0, prices, dp);
        sellMax = max(sell, notSell);
    }
    return dp[day][limit][buyFlag] = max(buyMax, sellMax);
}
int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, -1)));
    return getMaxProfit(0, k, 1, prices, dp);
}
// Tabulation
// Time complexity O(n*k*2)
// Space complexity O(n*k*2)
int maxProfit(int k_transaction, vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k_transaction + 1, vector<int>(2, -1)));
    for(int i=n; i >= 0; --i) {
        // transaction remaining
        for(int j=0; j <= k_transaction; ++j) {
            // buy or sell
            for(int k=0; k < 2; ++k) {
                if(i==n || j==0) {
                    dp[i][j][k] = 0;
                }
                else {
                    int sellMax = INT_MIN, buyMax = INT_MIN;
                    // sell
                    if(k==0) {
                        int sell = prices[i] + dp[i+1][j-1][1];
                        int notSell = dp[i+1][j][0];
                        sellMax = max(sell, notSell);
                    }
                    // buy
                    else {
                        int buy = - prices[i] + dp[i+1][j][0];
                        int notBuy = dp[i+1][j][1];
                        buyMax = max(buy, notBuy);
                    }
                    dp[i][j][k] = max(sellMax, buyMax);
                }
            }
        }
    }
    return dp[0][k_transaction][1];
}
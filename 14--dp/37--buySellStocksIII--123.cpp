// Best time to buy and sell stocks III -- leetcode 123
// Memoization
// Time complexity O(n*3*2) 
// Space complexity O(n*3*2) + Recursion stack space O(n)
int getMaxProfit(int day, int limit, int buyPossible, vector<int>& prices, vector<vector<vector<int>>> &dp) {
    if(day==prices.size() || limit==0) return 0;
    if(dp[day][limit][buyPossible] != -1) return dp[day][limit][buyPossible];
    int buyMax = INT_MIN, sellMax = INT_MIN;
    if(buyPossible==1) {
        int buy = getMaxProfit(day+1, limit, 0, prices, dp) - prices[day];
        int notBuy = getMaxProfit(day+1, limit, 1, prices, dp);
        buyMax = max(buy, notBuy);
    }
    else {
        int sell = getMaxProfit(day+1, limit-1, 1, prices, dp) + prices[day];
        int notSell = getMaxProfit(day+1, limit, 0, prices, dp);
        sellMax = max(sell, notSell);
    }
    return dp[day][limit][buyPossible] = max(buyMax, sellMax);
}
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int limit = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(limit+1, vector<int>(2, -1)));
    return getMaxProfit(0, limit, 1, prices, dp);
}


// Tabulation
// Time complexity O(n*k*2)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2)));
    for(int i=n; i>=0; --i) {
        // transaction remaining
        for(int j=0; j<3; ++j) {
            // buy or sell
            for(int k=0; k<2; ++k) {
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
    return dp[0][2][1];
}
// Best time to buy and sell stocks with single transaction -- leetcode 121
// Time complexity O(n)
// Space complexity O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1) return 0;
    int minValue = prices[0];
    int maxProfit = 0;
    for(int i=1; i<n; ++i) {
        if(minValue < prices[i]) {
            int currProfit = prices[i] - minValue;
            maxProfit = max(maxProfit, currProfit);
        }
        if(minValue > prices[i]) {
            minValue = prices[i];
        }
    }
    return maxProfit;
}
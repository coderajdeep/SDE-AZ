// Best Time to buy and sell stock -- leetcode 121

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1) return 0;
    int currProfit = 0, minPrice = prices[0], maxProfit = 0;
    for(int i=1; i<n; ++i) {
        if(prices[i]>minPrice) {
            currProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currProfit);
        }
        minPrice = min(minPrice, prices[i]);
    }
    return maxProfit;
}


// When we need to find the buy and sell day
pair<int, int> maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1) return 0;
    int currProfit = 0, minPrice = prices[0], maxProfit = 0;
    int lo = 0, low = 0, high;
    for(int i=1; i<n; ++i) {
        if(prices[i]>minPrice) {
            currProfit = prices[i] - minPrice;
            if(currProfit>maxProfit) {
                maxProfit = currProfit;
                low = lo;
                high = i;
            }
        }
        if(minPrice>prices[i]) {
            minPrice = prices[i];
            lo = i;
        }
    }
    return pair<int, int> {low, high};
}
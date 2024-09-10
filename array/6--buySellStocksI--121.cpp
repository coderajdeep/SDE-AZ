// Best time to buy and sell stocks
// One transaction allowed

// Time complexity O(nlogn)
// Space complexity O(n)
// Using Priority queue (Min Heap)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1) return 0;
    int profit = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(prices[0]);
    for(int i=1; i<n; ++i) {
        int top = pq.top();
        profit = max(profit, prices[i]-top);
        pq.push(prices[i]);
    }
    return profit;
}

// Time complexity O(n)
// Space compelxity O(1)
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n==1) return 0;
    int profit = 0;
    int currMin = prices[0];
    for(int i=1; i<n; ++i) {
        profit = max(profit, (prices[i]-currMin));
        currMin = min(currMin, prices[i]);
    }
    return profit;
}
// 0 1 Knapsack -- Geeks
// https://leetcode.com/problems/maximum-profit-from-trading-stocks/
// Memoization
// Time complexity O(n*maxWeight)
// Space complexity O(n*maxWeight) + Recursion stack space 0(n)
int solve(int index, int W, int *wt, int *val, vector<vector<int>> &dp) {
	if(W==0) return 0;
	if(index==0) return (wt[0]<=W)?((W/wt[0])*val[0]):0;
	if(dp[index][W]!=-1) return dp[index][W];
	int take = 0;
	if(wt[index]<=W) take = val[index] + solve(index, W-wt[index], wt, val, dp);
	int notTake = solve(index-1, W, wt, val, dp);
	return dp[index][W] = max(take, notTake);
}
int knapSack(int N, int W, int val[], int wt[]) {
	vector<vector<int>> dp(N, vector<int>(W+1, -1));
	int ans = solve(N-1, W, wt, val, dp);
	return ans;
}

// Tabulation
// Time complexity O(n*maxWeight)
// Space complexity O(n*maxWeight)
int knapSack(int N, int W, int val[], int wt[]) {
	vector<vector<int>> dp(N, vector<int>(W+1));
	for(int i=0; i<N; ++i) {
		dp[i][0] = 0;
		for(int j=1; j<=W; ++j) {
			if(i==0) {
				if(wt[0]<=j) {
					dp[i][j] = (j/wt[0]) * val[0];
				}
				else {
					dp[i][j] = 0;
				}
			}
			else {
				int take = (wt[i]<=j) ? val[i] + dp[i][j-wt[i]] : 0;
				int notTake = dp[i-1][j];
				dp[i][j] = max(take, notTake);
			}
		}
	}
	return dp[N-1][W];
}

// Space optimized
// Uisng only one 1D array
// Time complexity O(n*maxWeight)
// Space complexity O(maxWeight)
int knapSack(int N, int W, int val[], int wt[]) {
	vector<int> dp(W+1);
	dp[0] = 0;
	for(int i=0; i<N; ++i) {
		for(int j=1; j<=W; ++j) {
			if(i==0) {
				if(wt[0]<=j) {
					dp[j] = (j/wt[0]) * val[0];
				}
				else {
					dp[j] = 0;
				}
			}
			else {
				int take = (wt[i]<=j) ? val[i] + dp[j-wt[i]] : 0;
				int notTake = dp[j];
				dp[j] = max(take, notTake);
			}
		}
	}
	return dp[W];
}
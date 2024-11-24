vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	int dp[n];
	int prevIndex[n];
	dp[0] = 1;
	prevIndex[0] = 0;
	int maxLen = 1, maxLenIndex = 0;
	for(int i=1; i<n; ++i) {
		dp[i] = 1;
		prevIndex[i] = i;
		for(int j=0; j<i; ++j) {
			if(arr[j]<arr[i] &&  dp[i] < dp[j]+1) {
				dp[i] = 1 + dp[j];
				prevIndex[i] = j;
				if(maxLen < dp[i]) {
					maxLen = dp[i];
					maxLenIndex = i;
				}
			}
		}
	}
	vector<int> ans(maxLen);
	int prev = maxLenIndex;
	for(int i=maxLen-1; i>=0; --i) {
		ans[i] = arr[prev];
		prev = prevIndex[prev];
	}
	return ans;
}

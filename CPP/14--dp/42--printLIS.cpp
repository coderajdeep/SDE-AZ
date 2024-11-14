vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	int dp[n];
	int hash[n];
	for(int i=0; i<n; ++i) {
		hash[i] = i;
		dp[i] = 1;
	}
	int maxIndex = 0, len = 1;
	for(int curr=1; curr<n; ++curr) {
		for(int prev=0; prev<curr; ++prev) {
			if(arr[prev]<arr[curr] && dp[prev]+1 > dp[curr]) {
				dp[curr] = 1 + dp[prev];
				hash[curr] = prev;
			}
		}
		if(len<dp[curr]) {
			len = dp[curr];
			maxIndex = curr;
		}
	}
	vector<int> ans(len);
	for(int i=len-1; i>=0; --i) {
		ans[i] = arr[maxIndex];
		maxIndex = hash[maxIndex];
	}
	return ans;
}

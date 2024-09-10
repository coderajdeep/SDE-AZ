int longestBitonicSubsequence(vector<int>& arr, int n) {
	vector<int> dp1(n, 1), dp2(n, 1);
	// Lis from front side
	// dp1[i] --> LIS value till i (including i) from front side
	for(int i=1; i<n; ++i) {
		for(int j=0; j<i; ++j) {
			if(arr[j] < arr[i] && (dp1[j] + 1 > dp1[i])) {
				dp1[i] = 1 + dp1[j];
			}
		}
	}

	// Lis from back side
	// dp2[i] --> LIS value till i (including i) from back side
	for(int i=n-2; i>=0; --i) {
		for(int j=n-1; j>i; --j) {
			if(arr[j] < arr[i] && (dp2[j] + 1 > dp2[i])) {
				dp2[i] = 1 + dp2[j];
			}
		}
	}
	int len = 1;
	for(int i=0; i<n; ++i) {
		// as we are calculationg index i length two tiimes
		len = max(len, dp1[i]+dp2[i]-1);
	}
	return len;
}

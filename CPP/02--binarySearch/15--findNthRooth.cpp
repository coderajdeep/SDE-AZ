// Find N'th root of M - Coding Ninja
// If N'th root is not integer then return -1
// Alternative question can be : return pair<int, int> {val1, val2}
// between val1 and v1l2 N'th root will exist
// where val1 is max possible value and val2 is minimum possible value
// When N'th rooth is integert then val1 == val2

// Time complexity O(logm * n)
// Space complexity O(1)

// This can be optimized to O(logn)
long powerOfN(int pow, int base, int actualM) {
	long ans = 1;
	for(int i=1; i<=pow; ++i) {
		ans = (ans * base);
		if(ans > actualM) return 1;
	}
	return (ans == actualM) ? 0 : -1;
}

int NthRoot(int n, int m) {
	if(n==1 || m==1) return m;
	int low = 2, high = m, mid;
	while(low<=high) {
		mid = low + (high - low) / 2;
		int powerValue = powerOfN(n, mid, m);
		if(powerValue == 0) return mid;
		if(powerValue == 1) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
	// If the n-th root is not integer, then flows reach here
	// the exact root will lies between (high, low)
}
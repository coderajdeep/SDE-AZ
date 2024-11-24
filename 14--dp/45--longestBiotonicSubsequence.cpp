// https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688
// Time complexity O(n*n)
// Space complexity O(n)
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

// Geeks
// https://www.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1
// Increasing and decreasing should not be empty
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        int dp1[n];
        int dp2[n];
        dp1[0] = dp2[n-1] = 1;
        
        for(int i=1; i<n; ++i) {
            int backIndex = n-i-1;
            dp1[i] = 1;
            dp2[backIndex] = 1;
            for(int j=0; j<i; ++j) {
                if(nums[j]<nums[i] && dp1[i] < dp1[j]+1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
            for(int j=n-1; j>backIndex; --j) {
                if(nums[j]<nums[backIndex] && dp2[backIndex] < dp2[j]+1) {
                    dp2[backIndex] = dp2[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; ++i) {
            if(dp1[i]>1 && dp2[i]>1) {
                ans = max(ans, dp1[i]+dp2[i]-1);
            }
        }
        return ans;
    }
};

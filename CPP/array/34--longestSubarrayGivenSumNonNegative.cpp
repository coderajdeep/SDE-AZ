// 34
// Longest Subarray with given sum (Array elements and given sum is non negative) - Coding Ninjas

// Time complexity O(n^2)
// Space complexity O(1)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    int ans = 0;
    for(int i=0; i<n; ++i) {
        long long sum = 0;
        for(int j=i; j<n; ++j) {
            sum += a[j];
            if(sum==k) {
                ans = max(ans, j-i+1);
            }
            else if(sum>k) {
                break;
            }
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();
    long long sum = 0;
    unordered_map<long long, int> um;
    um[0] = -1;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        sum += a[i];
        if(um.find(sum)==um.end()) {
            um[sum] = i;
        }
        auto it = um.find(sum-k);
        if(it!=um.end()) {
            ans = max(ans, (i - it->second));
        }
    }
    return ans;
}


// Time complexity O(n)
// Space complexity O(1)
int longestSubarrayWithSumK(vector<int>& a, long long k) {
    int n = a.size();
    int left = 0, right = 0, maxLen = 0;
    long long sum = a[0];
    while(right<n) {
        while(left<=right && sum>k) {
            sum -= a[left];
            left += 1;
        }
        if(sum==k) {
            maxLen = max(maxLen, (right-left+1));
        }
        right += 1;
        if(right<n) {
            sum += a[right];
        }
    }
    return maxLen;
}
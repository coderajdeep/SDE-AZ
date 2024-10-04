// Longest subarray with given sum
// https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_6682399
// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
// Solution 1 and 2 is important

// Solution 1
// Best approach
// variable size sliding window
// Time complexity O(n)
// Space complexity O(1)
// [1 1 1 1 5]
// k = 5
// Here we need to traverse the whole array two time
// Means Time complexity O(2*n)
// This will work when 0<=arr[i]
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int low = 0, high = 0, maxLen = 0, n = a.size();
    long long sum = 0;
    while(high<n) {
        sum += a[high];
        while(low<=high && sum>k) {
            sum -= a[low++];
        }
        if(sum == k) {
            maxLen = max(maxLen, high-low+1);
        }
        ++high;
    }
    return maxLen;
}

// Solution 2
// https://www.codingninjas.com/studio/problems/920321
// Time complexity O(n)
// Space complexity O(n)
// Just handling the case where 0 to i index is giving max length subarray
int lenOfLongSubarr(int A[],  int N, int K) { 
    unordered_map<int, int> prefixSum;
    prefixSum[0] = -1;
    int sum = 0, maxLen = 0;
    for(int i=0; i<N; ++i) {
        sum += A[i];
        auto it = prefixSum.find(sum - K);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
        // This is ensuring that the prefix having the earliest index 
        // So we can get the max length subarray
        if(prefixSum.find(sum)==prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}


// Time complexity O(n)
// Space complexity O(n)
int lenOfLongSubarr(int A[],  int N, int K) { 
    unordered_map<int, int> prefixSum;
    int sum = 0, maxLen = 0;
    for(int i=0; i<N; ++i) {
        sum += A[i];
        // when the subarray is [0..i]
        if(sum==K) {
            maxLen = i + 1;
        }
        if(prefixSum.find(sum)==prefixSum.end()) {
            prefixSum[sum] = i;
        }
        auto it = prefixSum.find(sum - K);
        if(it!=prefixSum.end()) {
            maxLen = max(maxLen, (i - it->second));
        }
    }
    return maxLen;
}

// Brute force approach
// Time complexity O(n^2)
// Space complexity O(1)
int lenOfLongSubarr(int A[],  int N, int K) { 
    int maxLen = 0;
    for(int i=0; i<N; ++i) {
        int sum = 0;
        for(int j=i; j<N; ++j) {
            sum += A[j];
            if(sum==K) {
                maxLen = max(maxLen, (j-i+1));
            }
            else if(sum>K) {
                break;
            }
        }
    }
    return maxLen;
}
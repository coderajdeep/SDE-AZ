// Partition array into two subsets with minimum absolute sum difference -- coding ninja (leetcode 2035 need to try)
// Partition equal subset sum -- leetcode 416
// Same problem as 14

// Time complexity O(n*sum)
// Space complexity O(sum)
// Space optimized
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; ++i) sum += arr[i];
    int prev[sum+1] = {0};
    int curr[sum+1] = {0};
    prev[0] = curr[0] = 1;
    // as all of the elements are non-negative
    // so arr[i] <= sum for all valid i
    if(arr[0] <= sum) prev[arr[0]] = 1;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=sum; ++j) {
            int pick = (arr[i] <= j) ? prev[j-arr[i]] : 0;
            int notPicked = prev[j];
            curr[j] = (pick || notPicked) ? 1 : 0;
        }
        for(int j=1; j<=sum; ++j) {
            prev[j] = curr[j];
        }
    }
    int minDiff = INT_MAX;
    for(int i=0; i<=sum; ++i) {
        if(prev[i]==1) {
            minDiff = min(minDiff, abs(2*i - sum));
        }
    }
    return minDiff;
}

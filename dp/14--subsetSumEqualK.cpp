// Subset sum equal to K -- coding ninjas

// Memoization
// Time complexity O(n*k)
// Space complexity O(n*k) + Recursion Stack space O(n*k)
bool subsetUtils(int index, int k, vector<int> &arr, vector<vector<int>> &dp) {
    // base case
    if(k==0) return true;
    if(k<0) return false;
    if(index<0) return false;
    
    if(dp[index][k] != -1) return (dp[index][k] == 1);
    bool pick = subsetUtils(index-1, k-arr[index], arr, dp);
    bool notPicked = subsetUtils(index-1, k, arr, dp);
    dp[index][k] = (pick || notPicked) ? 1 : 0;
    return pick || notPicked;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return subsetUtils(n-1, k, arr, dp);
}

// Tabulation
// Time complexity O(n*k)
// Space complexity O(n*k)

// dp[i][j] 
// last index of array is i and given sum is j
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k+1));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=k; ++j) {
            // order if this if else block is important
            // if k == 0 then there will be always an empty subset which sum is 0
            if(j==0) dp[i][j] = true;
            else if(i==0) dp[i][j] = (arr[0]==j);
            else {
                // if i indexed array value is less or equal to k then only we can include the element into the subset
                bool pick = (arr[i] <= j) ? dp[i-1][j-arr[i]] : false;
                bool notPicked = dp[i-1][j];
                dp[i][j] = (pick || notPicked);
            }
        }
    }
    return dp[n-1][k];
}

// Space optimized
// Time complexity O(n*k)
// Space complexity O(k)
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false), curr(k+1);
    prev[0] = curr[0] = true;
    if(arr[0]<=k) prev[arr[0]] = true;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=k; ++j) {
            bool pick = (arr[i] <= j) ? prev[j-arr[i]] : false;
            bool notPicked = prev[j];
            curr[j] = (pick || notPicked); 
        }
        for(int j=1; j<=k; ++j) prev[j] = curr[j];
    }
    return prev[k];
}
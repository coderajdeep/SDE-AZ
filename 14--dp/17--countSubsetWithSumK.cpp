// Count subset with sum K -- Coding Ninjas
// *** Best Solution (Solution 2 -- using only one !D array)
// Solution 1
// Space optimized Geeks
// Time complexity O(n*sum)
// Space complexity O(sum)
int perfectSum(int arr[], int n, int sum) {
    int mod = 1e9+7;
    vector<int> prev(sum+1), curr(sum+1);
    // If arr[0] == 0
    // then we can include or exclude arr[0] into our subset
    // that's why answer is 2
    // ***
    prev[0] = (arr[0]==0) ? 2 : 1;
    for(int i=1; i<=sum; ++i) {
        prev[i] = (arr[0]==i) ? 1 : 0;
    }
    for(int i=1; i<n; ++i) {
        // ***
        // we have to start from j=0
        // otherwise we will miss count when sum = 0 and there are multiple zero present in array
        // [0 0 0] sum = 0
        // Dry run this 
        for(int j=0; j<=sum; ++j) {
            int take = (arr[i]<=j) ? prev[j-arr[i]] : 0;
            int notTake = prev[j];
            curr[j] = (take + notTake) % mod;
        }
        for(int j=0; j<=sum; ++j) {
            prev[j] = curr[j];
        }
    }
    return prev[sum];
}

// Solution 2
// Just using one 1D array
int perfectSum(int arr[], int n, int sum) {
    int dp[sum+1] = {0};
    if(arr[0]<=sum) dp[arr[0]] = 1;
    dp[0] = (arr[0]==0) ? 2 : 1;
    int mod = 1e9+7;
    for(int i=1; i<n; ++i) {
        for(int j=sum; j>=0; --j) {
            int take = (arr[i]<=j) ? dp[j-arr[i]] : 0;
            int notTake = dp[j];
            dp[j] = (take + notTake) % mod;
        }
    }
    return dp[sum];
}


// Space optimised
// Time complexity O(n*k)
// Space complexity O(k)
// 0 <= arr[i] <=1000
int findWays(vector<int>& arr, int k)
{
    int n = arr.size(), mod = 1e9+7;
    vector<int> prev(k+1, 0), curr(k+1);
    // By default if sum == 0 then prev[0] = 1
    prev[0] = 1;
    // If arr[0] == 0
    // then we can include or exclude arr[0] into our subset
    // that's why answer is 2
    if(arr[0]==0) prev[0] = 2;
    else {
        if(arr[0] <= k) prev[arr[0]] = 1;
    }

    for(int i=1; i<n; ++i) {
        for(int j=0; j<=k; ++j) {
            int pick = (arr[i] <= j) ? prev[j-arr[i]] : 0;
            int notPick = prev[j];
            curr[j] = (pick + notPick) % mod;
        }
        for(int j=0; j<=k; ++j) {
            prev[j] = curr[j];
        }
    }
    return prev[k]; 
}


// Bottom up
// Tabulation
// Time complexity O(n*k)
// Space complexity O(n*k)
// 0 <= arr[i] <=1000
int findWays(vector<int>& arr, int k)
{
    int n = arr.size(), mod = 1e9+7;
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    
    dp[0][0] = 1;
    if(arr[0]==0) dp[0][0] = 2;
    else if(arr[0] <= k) dp[0][arr[0]] = 1;

    for(int i=1; i<n; ++i) {
        for(int j=0; j<=k; ++j) {
            int pick = (arr[i] <= j) ? dp[i-1][j-arr[i]] : 0;
            int notPick = dp[i-1][j];
            dp[i][j] = (pick + notPick) % mod;
        }
    }
    return dp[n-1][k]; 
}

// Top down approach
// Memoization
// Time complexity O(n*k)
// Space complexity O(n*k) + Recursion stack space O(n*k)
// https://youtu.be/zoilQD1kYSg
// How to handle when // 0 <= arr[i] <=1000
const int mod = 1e9 + 7;
int getTotalSubsetSum(int index, int k, vector<int> &nums, vector<vector<int>> &dp) {
    if(k<0) return 0;
    if(index==0) {
        if(k==0 && nums[0]==0) return 2;
        else if(k==0 || nums[0]==k) return 1;
        else return 0;
    }
    if(dp[index][k] != -1) return dp[index][k];
    int pick = getTotalSubsetSum(index-1, k-nums[index], nums, dp) % mod;
    int notPick = getTotalSubsetSum(index-1, k, nums, dp) % mod;
    return dp[index][k] = (pick + notPick) % mod;
}

int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return getTotalSubsetSum(n-1, k, arr, dp);
}
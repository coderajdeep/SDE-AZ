// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, int sum, vector<int> &arr, vector<int> &subset, vector<vector<int>> &subsets) {
    if(index == n) {
        if(sum == 0) {
            subsets.push_back(subset);
        }
        return;
    }
    solve(index+1, n, sum, arr, subset, subsets);
    subset.push_back(arr[index]);
    solve(index+1, n, sum-arr[index], arr, subset, subsets);
    subset.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> subset;
    vector<vector<int>> subsets;
    solve(0, n, k, arr, subset, subsets);
    return subsets;
}

// Count subsets having sum K
// Time complexity O(n*sum)
// Space complexity O(sum)
// Using only one 1D array
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
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

// Best Space optimized (Using single 1D array)
// Time complexity O(n*k)
// Space complexity O(k)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<bool> dp(target+1);
        dp[0] = true;
        for(int i=1; i<=target; ++i) {
            dp[i] = (arr[0]==i);
        }
        for(int i=1; i<n; ++i) {
            for(int j=target; j>=1; --j) {
                bool take = (arr[i]<=j) ? dp[j-arr[i]] : false;
                bool notTake = dp[j];
                dp[j] = take || notTake;
            }
        }
        return dp[target];
    }
};

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


// Print the subset
vector<int> getSubset(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1));
    for (int i = 0; i <= k; ++i) {
        dp[0][i] = (nums[0] == i);
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            bool take = (nums[i] <= j) ? dp[i][j - nums[i]] : false;
            bool notTake = dp[i - 1][j];
            dp[i][j] = take || notTake;
        }
    }
    vector<int> subset;
    int j = k;
    // Traverse from the last index down to 1.
    for (int i = n - 1; i > 0 && j > 0; i--) {
        // If the current element is used in forming sum j,
        // then dp[i][j] would be true but dp[i-1][j] would be false
        // OR j can only be achieved by including nums[i].

        // In simple words, if dp[i][j] is true and dp[i-1][j] is false
        // then only way dp[i][j] can be true by including the current element i.e. nums[i]
        if (dp[i][j] && j >= nums[i] && !dp[i - 1][j]) {
            subset.push_back(nums[i]);
            j -= nums[i];
        }
        // Otherwise, the current element was not used.
    }

    // After processing indices 1...n-1, check index 0.
    if (j > 0 && j == nums[0])
        subset.push_back(nums[0]);

    return subset;
}
// Time complexity O(n*k)
// Space complexity O(k)
bool isSubsetPresent(int n, int k, vector<int> &a)
{
    bool dp[k+1];
    for(int i=0; i<=k; ++i) {
        if(i==0 || i==a[0]) {
            dp[i] = true;
        }
        else {
            dp[i] = false;
        }
    }
    for(int i=1; i<n; ++i) {
        for(int j=k; j>=1; --j) {
            bool take = (a[i]<=j) ? dp[j-a[i]] : false;
            bool notTake = dp[j];
            dp[j] = (take || notTake);
        }
    }
    return dp[k];
}
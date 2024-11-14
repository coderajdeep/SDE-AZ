// Solution 1
// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, int target, vector<int> &candidates, vector<int> &subset, vector<vector<int>> &subsets) {
    if(target == 0) {
        subsets.push_back(subset);
        return;
    }
    if(target < 0 || index ==  n) return;
    subset.push_back(candidates[index]);
    solve(index, n, target-candidates[index], candidates, subset, subsets);
    subset.pop_back();
    solve(index+1, n, target, candidates, subset, subsets);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> subset;
    vector<vector<int>> subsets;
    solve(0, candidates.size(), target, candidates, subset, subsets);
    return subsets;
}


// Solution 2
void solve(int index, int n, int sum, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans) {
    if(index==n) {
        if(sum==0) {
            ans.push_back(ds);
        }
        return;
    }
    
    if(arr[index]<=sum) {
        ds.push_back(arr[index]);
        solve(index, n, sum-arr[index], arr, ds, ans);
        ds.pop_back();
    }
    solve(index+1, n, sum, arr, ds, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    int n = candidates.size();
    if(n==0) return {};
    
    vector<vector<int>> ans;
    vector<int> ds;
    
    solve(0, n, target, candidates, ds, ans);
    return ans;
}
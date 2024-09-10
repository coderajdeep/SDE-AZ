// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, int target, vector<int> &candidates, vector<int> &subset, vector<vector<int>> &subsets) {
    if(target==0) {
        subsets.push_back(subset);
    }
    if(target<0) {
        return;
    }
    for(int i=index; i<n; ++i) {
        if(i>index && candidates[i-1]==candidates[i]) continue;
        subset.push_back(candidates[i]);
        solve(i+1, n, target-candidates[i], candidates, subset, subsets);
        subset.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> subset;
    vector<vector<int>> subsets;
    sort(candidates.begin(), candidates.end());
    int n = candidates.size();
    solve(0, n, target, candidates, subset, subsets);
    return subsets;
}
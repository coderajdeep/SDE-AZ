// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets) {
    subsets.push_back(subset);
    for(int i=index; i<n; ++i) {
        if(i>index && nums[i-1]==nums[i]) continue;
        subset.push_back(nums[i]);
        solve(i+1, n, nums, subset, subsets);
        subset.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> subset;
    vector<vector<int>> subsets;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    solve(0, n, nums, subset, subsets);
    return subsets;
}
// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int k, int target, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets) {
    if(subset.size()==k && target==0) {
        subsets.push_back(subset);
        return;
    }
    if(target<0 || subset.size()>k || index==nums.size()) {
        return;
    }
    subset.push_back(nums[index]);
    solve(index+1, k, target-nums[index], nums, subset, subsets);
    subset.pop_back();
    solve(index+1, k, target, nums, subset, subsets);
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9}, subset;
    vector<vector<int>> subsets;
    solve(0, k, n, nums, subset, subsets);
    return subsets;
}
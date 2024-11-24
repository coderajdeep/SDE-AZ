// Generate all subsets/subsequence of an array -- leetcode 78
// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, vector<int> &nums, vector<int> &subset, vector<vector<int>> &subsets) {
    if(index==n) {
        subsets.push_back(subset);
        return;
    }
    
    // both will work

    // subset.push_back(nums[index]);
    // solve(index+1, n, nums, subset, subsets);
    // subset.pop_back();
    // solve(index+1, n, nums, subset, subsets);
    
    solve(index+1, n, nums, subset, subsets);
    subset.push_back(nums[index]);
    solve(index+1, n, nums, subset, subsets);
    subset.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> subset;
    vector<vector<int>> subsets;
    solve(0, n, nums, subset, subsets);
    return subsets;
}


// Similar with previous one
void utils(int index, int n, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans) {
    if(index == n) {
        ans.push_back(temp);
        return;
    }
    // take the index element
    temp.push_back(nums[index]);
    utils(index + 1, n, nums, temp, ans);
    // backtrack by removing the element
    temp.pop_back();
    utils(index + 1, n, nums, temp, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp;
    vector<vector<int>> ans;
    utils(0, n, nums, temp, ans);
    return ans;
}
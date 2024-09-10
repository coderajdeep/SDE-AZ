// Time complexity O(2^n * n)
// Space complexity O(2^n * n) [for storing subsets] + O(n) [for storing the array while backtracking] + O(n) [Recursive stack space]
void solve(int index, int n, int sum, vector<int> &arr, vector<int> &ans) {
    if(index==n) {
        ans.push_back(sum);
        return;
    }
    solve(index+1, n, sum+arr[index], arr, ans);
    solve(index+1, n, sum, arr, ans);
}
vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> ans;
    solve(0, n, 0, arr, ans);
    return ans;
}
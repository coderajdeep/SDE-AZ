// Time complexity O(2^n * n)
// Space complexity (recursion stack space) O(n) + O(2^n * n) (storing the answer)
void solve(int index, int n, vector<int> &arr, vector<int> &subset, vector<vector<int>> &subsets) {
    subsets.push_back(subset);
    for(int i=index; i<n;++i) {
        if(i>index && arr[i-1]==arr[i]) continue;
        subset.push_back(arr[i]);
        solve(i+1, n, arr, subset, subsets);
        subset.pop_back();
    }
}
vector<vector<int> > AllSubsets(vector<int> arr, int n)
{
    vector<int> subset; 
    vector<vector<int>> subsets;
    sort(arr.begin(), arr.end());
    solve(0, n, arr, subset, subsets);
    return subsets;
}

// Time complexity O(2^n * n)
// Space complexity (recursion stack space) O(n) + O(2^n * n) (storing the answer)
void solve(int index, int n, vector<int> &arr, unordered_set<int> &uset, vector<int> &subset, vector<vector<int>> &subsets) {
    if(index == n) {
        subsets.push_back(subset);
        return;
    }
    if(uset.find(arr[index]) != uset.end()) {
        subset.push_back(arr[index]);
        uset.insert(arr[index]);
        solve(index+1, n, arr, uset, subset, subsets);
        subset.pop_back();
        uset.erase(arr[index]);
    }
    else {
        solve(index+1, n, arr, uset, subset, subsets);
        subset.push_back(arr[index]);
        uset.insert(arr[index]);
        solve(index+1, n, arr, uset, subset, subsets);
        subset.pop_back();
        uset.erase(arr[index]);
    }
}
vector<vector<int> > AllSubsets(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    unordered_set<int> uset;
    vector<int> subset; 
    vector<vector<int>> subsets;
    solve(0, n, arr, uset, subset, subsets);
    sort(subsets.begin(), subsets.end());
    return subsets;
}
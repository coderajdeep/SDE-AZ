// Power set -- leetcode 78

// Simple approach
// Time complexity O(n * 2^n)
// Space complexity O(n * 2^n)
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size();
    int totalSubset = (1<<n);
    // total 2^n or (1<<n) number of subset possible
    // from 0 to 2^n-1
    // if the bit position is set
    // then we can pick the number for the subsequence
    vector<vector<int>> ans;
    for(int i=0; i<totalSubset; ++i) {
        vector<int> temp;
        for(int j=0; j<n; ++j) {
            if(i & (1<<j)) {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

// Time complexity O(n * 2^n)
// Space complexity O(n * 2^n)
// Here Inner for loop will not run till n-1
vector<vector<int>> subsets(vector<int>& nums) {
    int n = nums.size(), num;
    int totalSubset = (1<<n);
    vector<vector<int>> ans;
    vector<int> temp;
    for(int i=0; i<totalSubset; ++i) {
        num = i;
        for(int j=0; (num!=0 && j<n); ++j) {
            if(num & 1) {
                temp.push_back(nums[j]);
            }
            num = (num>>1);
        }
        ans.push_back(temp);
        temp.clear();
    }
    return ans;
}
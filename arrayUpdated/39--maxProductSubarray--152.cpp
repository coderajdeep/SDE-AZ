// Subarray with maximum product -- leetcode 152
// Time complexity O(n)
// Space complexity O(1)

int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans = INT_MIN;
    int prefix = 1;
    for(int i=0; i<n; ++i) {
        if(nums[i] != 0) {
            prefix = prefix * nums[i];
            ans = max(ans, prefix);
        }
        else {
            prefix = 1;
            ans = max(ans, 0);
        }
    }
    int suffix = 1;
    for(int i=n-1; i>=0; --i) {
        if(nums[i] != 0) {
            suffix = suffix * nums[i];
            ans = max(ans, suffix);
        }
        else {
            suffix = 1;
            ans = max(ans, 0);
        }
    }
    return ans;
}
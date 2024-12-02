// Subarray with maximum product -- leetcode 152
// Time complexity O(n)
// Space complexity O(1)

// Single traversal
// https://youtu.be/hnswaLJvr6g?t=1148
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    int prefix = 1, suffix = 1, ans = INT_MIN;
    for(int i=0; i<n; ++i) {
        prefix = (prefix * nums[i]);
        ans = max(ans, prefix);
        suffix = (suffix * nums[n-1-i]);
        ans = max(ans, suffix);
        if(prefix==0) prefix = 1;
        if(suffix==0) suffix = 1;
    }
    return ans;
}

// two traversal
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

// Brute force
// Time complexity O(n*n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        for(int i=0; i<n; ++i) {
            int product = 1;
            for(int j=i; j<n; ++j) {
                product = (product * nums[j]);
                ans = max(ans, product);
            }
        } 
        return ans;
    }
};
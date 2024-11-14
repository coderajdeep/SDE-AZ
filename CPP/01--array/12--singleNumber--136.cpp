// Find only single element in array  -- leetcode 136

// Best approach
// Time complexity O(n)
// Space complexity O(1)
int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(const int num:nums) {
        ans = (ans ^ num);
    }
    return ans;
}
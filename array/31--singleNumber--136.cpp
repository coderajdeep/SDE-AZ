// 31
// Find the single element - leetcode 136

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num:nums) {
        ans = (ans^num);
    }
    return ans;
}
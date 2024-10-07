// Single number -- leetcode 136

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(const int num:nums) {
        ans = (ans ^ num);
    }
    return ans;
}
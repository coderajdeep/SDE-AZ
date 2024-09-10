// Time complexity O(n)
// Space complexity O(1)
bool canJump(vector<int>& nums) {
    int n = nums.size(), maxIndex = 0;
    for(int i=0; i<n; ++i) {
        if(i > maxIndex) return false;
        maxIndex = max(maxIndex, i+nums[i]);
    }
    return true;
}
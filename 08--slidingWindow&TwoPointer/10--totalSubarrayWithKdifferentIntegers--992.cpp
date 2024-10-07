// Subarray with K different Integers -- leetcode 992
// Time complexity O(n)
// Space complexity O(k)
int getAtmostKdifferentIntegers(vector<int>& nums, int k) {
    int low = 0, high = 0, n = nums.size();
    long count = 0;
    unordered_map<int, int> umap;
    while(high < n) {
        umap[nums[high]]++;
        while(low <= high && k < umap.size()) {
            umap[nums[low]]--;
            if(umap[nums[low]]==0) {
                umap.erase(nums[low]);
            }
            ++low;
        }
        count += (high - low + 1);
        ++high;
    }
    return count;
}
int subarraysWithKDistinct(vector<int>& nums, int k) {
    return (getAtmostKdifferentIntegers(nums, k) - getAtmostKdifferentIntegers(nums, k-1));
}
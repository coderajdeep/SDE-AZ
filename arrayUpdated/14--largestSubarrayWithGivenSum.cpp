// Time complexity O(n)
// Space complexity O(n)

int getLongestSubarray(vector<int>& nums, int k){
    int sum = 0, maxLen = 0, n = nums.size();
    unordered_map<int, int> um;
    // this is for handling sum from index 0 to i
    um[0] = -1;
    for(int i=0; i<n; ++i) {
        sum += nums[i];
        auto itr = um.find(sum - k);
        if(itr != um.end()) {
            maxLen = max(maxLen, i - itr->second);
        }
        // This is ensuring that the prefix having the earliest index 
        // So we can get the max length subarray
        if(um.find(sum)==um.end()) {
            um[sum] = i;
        }
    }
    return maxLen;
}
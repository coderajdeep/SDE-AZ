// Binary subarray with given sum -- leetcode 930


// Solution 1
// Best approach
// Time complexity O(n)
// Space complexity O(1)
long countSubarrayLessEqualSum(vector<int>& nums, int goal) {
    if(goal < 0) return 0;
    int low = 0, high = 0, n = nums.size();
    long count = 0, sum = 0;
    while(high < n) {
        sum += nums[high];
        while(low<=high && sum>goal) {
            sum -= nums[low++];
        }
        // very important concept ***
        // total subarray having ending index high in low to high interval
        // these are the subarray
        // [low high] [low+1 high] [low+2 high] ... [high high]
        count += (high - low + 1);
        ++high;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return countSubarrayLessEqualSum(nums, goal) - countSubarrayLessEqualSum(nums, goal-1);
}

// Solution 2
// Time complexity O(n)
// Space complexity O(n)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, ans = 0;
    for(int num : nums) {
        sum += num;
        auto it = prefixSum.find(sum -  goal);
        if(it != prefixSum.end()) {
            ans += it->second;
        }
        prefixSum[sum]++;
    }
    return ans;
}
// Count number of nice subarray -- leetcode 1248
// We can convert the array to binary subarray (odd to 1 and others to 0)
// Then it will be similar to - find number of subarray with given sum 

// Time complexity O(n)
// Space complexity O(n)
int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, ans = 0, odd;
    for(int num : nums) {
        odd = (num & 1) ? 1 : 0;
        sum += odd;
        auto it = prefixSum.find(sum - k);
        if(it != prefixSum.end()) {
            ans += it->second;
        }
        prefixSum[sum]++;
    }
    return ans;
}


// Time complexity O(n)
// Space complexity O(1)
int getSubarrayCount(vector<int>& nums, int k) {
    if(k < 0) return 0;
    int sum = 0, ans = 0, low = 0, high = 0, n = nums.size(), num;
    while(high < n) {
        num = (nums[high] & 1);
        sum += num;
        while(low<=high && sum>k) {
            num = (nums[low++] & 1);
            sum -= num;
        }
        ans += (high - low + 1);
        ++high;
    }
    return ans;
}
long countSubarrayLessEqualSum(vector<int>& nums, int goal) {
    if(goal < 0) return 0;
    int low = 0, high = 0, n = nums.size();
    long count = 0, sum = 0;
    while(high < n) {
        sum += nums[high];
        while(low<=high && sum>goal) {
            sum -= nums[low++];
        }
        count += (high - low + 1);
        ++high;
    }
    return count;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    return getSubarrayCount(nums, k) - getSubarrayCount(nums, k-1);
}
// Similar to binary subarray having sum K (constant space solution)
// Time complexity O(n)
// Space complexity O(1)
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 1 <= k <= 1015
long long countSubarrays(vector<int>& nums, long long k) {
    long long count = 0, sum = 0, score = 0, left = 0, right = 0, n = nums.size();
    while(right<n) {
        sum += nums[right];
        score = sum * (right - left + 1);
        while(left<=right && score>=k) {
            sum -= nums[left++];
            score = sum * (right - left + 1);
        }
        count += (right - left + 1);
        ++right;
    }
    return count;
}
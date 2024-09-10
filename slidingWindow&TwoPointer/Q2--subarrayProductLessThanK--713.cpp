// Time complexity O(n)
// Space complexity O(1)
// 1 <= nums.length <= 3 * 104
// 1 <= nums[i] <= 1000
// 0 <= k <= 106

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k==0) return 0;
    int left = 0, right = 0, count = 0, n = nums.size();
    long product = 1;
    while(right<n) {
        product *= nums[right];
        while(left<=right && product>=k) {
            product /= nums[left++];
        }
        count += (right-left+1);
        ++right;
    }
    return count;
}
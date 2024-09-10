// Max consecutive one III -- leetcode 1004

// Time complexity O(2*n)
// Space complexity O(1)
int longestOnes(vector<int>& nums, int k) {
    int low = 0, high = 0, n = nums.size(), maxLength = 0, count = 0;
    while(high < n) {
        if(nums[high]==1 || count < k) {
            maxLength = max(maxLength, high - low + 1);
            if(nums[high]==0) ++count;
            ++high;
        }
        else {
            if(nums[low]==0) --count;
            ++low;
        }
    }
    return maxLength;
}
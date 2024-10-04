// Max consecutive one III -- leetcode 1004

// Time complexity O(2*n)
// Space complexity O(1)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0, high = 0, maxLength = 0, flipCount = 0, n = nums.size();
        while(high<n) {
            if(nums[high]==1 || flipCount<k) {
                maxLength = max(maxLength, high-low+1);
                if(nums[high] != 1) ++flipCount;
                ++high;
            }
            else {
                if(nums[low] != 1) --flipCount;
                ++low;
            }
        }
        return maxLength;
    }
};
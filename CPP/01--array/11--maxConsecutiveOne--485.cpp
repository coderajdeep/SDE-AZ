// Maximum consecutive one 
// leetcode 485
// Best approach
// Time complexity O(n)
// Space complexity O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size(), count = 0, maxCount = 0;
    for(int i=0; i<n; ++i) {
        if(nums[i]) {
            ++count;
            maxCount = max(maxCount, count);
        }
        else {
            count = 0;
        }
    }
    return maxCount;
}

// leetcode 1004
// Maximum consecutive one III
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
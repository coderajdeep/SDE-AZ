// 32
// Max Consecutive Ones -- leetcode 485


// Time complexity O(n)
// Space complexity O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
    int count = 0, maxCount = 0;
    for(int i=0; i<n; ++i) {
        if(nums[i]==0) {
            maxCount = max(maxCount, count);
            count = 0;
        }
        else {
            ++count;
        }
    }
    maxCount = max(maxCount, count);
    return maxCount;
}

// Time complexity O(n)
// Space complexity O(1)
int findMaxConsecutiveOnes(vector<int>& nums) {
    int count = 0, maxCount = 0;
    for(int num:nums) {
        if(num==1) {
            ++count;
            maxCount = max(maxCount, count);
        }
        else {
            count = 0;
        }
    }
    return maxCount;
}
// Partition equal subset sum -- leetcode 416
// Same problem as 14
// Time complexity O(n * sum)
// Space complexity O(sum)
bool canPartition(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    for(int i=0; i<n; ++i) sum += nums[i];
    // if total sum is odd then we can't equally divide into two subset 
    if(sum & 1) return false;
    sum /= 2;
    vector<bool> prev(sum+1, false), curr(sum+1);
    prev[0] = curr[0] = true;
    if(nums[0]<=sum) prev[nums[0]] = true;
    for(int i=1; i<n; ++i) {
        for(int j=1; j<=sum; ++j) {
            bool pick = (nums[i] <= j) ? prev[j - nums[i]] : false;
            bool notPick = prev[j];
            curr[j] = (pick || notPick);
        }
        for(int j=1; j<=sum; ++j) prev[j] = curr[j];
    }
    return prev[sum];
}
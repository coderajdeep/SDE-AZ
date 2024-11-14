// Target Sum -- leetcode 494
// Time complexity O(n*tar)
// Space complexity O(tar)
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0, n = nums.size();
    for(int i=0; i<n; ++i) sum += nums[i];
    int tar = (sum-target);
    if(tar<0 || (tar&1)) return 0;
    tar /= 2;
    vector<int> prev(tar+1, 0), curr(tar+1);
    prev[0] = 1;
    if(nums[0]==0) prev[0] = 2;
    else if(nums[0]<=tar) prev[nums[0]] = 1;
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=tar; ++j) {
            int pick = (nums[i]<=j) ? prev[j-nums[i]] : 0;
            int notPick = prev[j];
            curr[j] = (pick + notPick);
        }
        for(int j=0; j<=tar; ++j) prev[j] = curr[j];
    }
    return prev[tar];
}
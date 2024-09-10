// Leetcode 18
// 4sum
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if(n<4) return vector<vector<int>> {};
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-3; ++i) {
        // This is for avoiding duplicates while moving i
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n-2; ++j) {
            // This is for avoiding duplicates while moving j
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            int start = j+1, end = n-1;
            while(start<end) {
                long sum = (long)nums[i] + (long)nums[j] + (long)nums[start] + (long)nums[end];
                if(sum==(long)target) {
                    ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                    ++start;
                    --end;
                    // This is for avoiding duplicates
                    while(start<end && nums[start]==nums[start-1]) ++start;
                    while(start<end && nums[end]==nums[end+1]) --end;
                }
                else if (sum>target) {
                    --end;
                }
                else {
                    ++start;
                }
            }
        }
    }
    return ans;
}
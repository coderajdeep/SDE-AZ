// 3Sum
// Leetcode 15

// 3sum best
// Time complexity O(nlogn) + O(n*n)
// Space complexity O(1)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<n-2; ++i) {
        if(i>0 && nums[i]==nums[i-1]) continue;
        int start = i+1, end = n-1;
        while(start<end) {
            int sum = nums[i] + nums[start] + nums[end];
            if(sum==0) {
                ans.push_back(vector<int> {nums[i], nums[start], nums[end]});
                ++start;
                --end;
                while(start<end && nums[start]==nums[start-1]) ++start;
                while(start<end && nums[end]==nums[end+1]) --end;
            }
            else if(sum>0) {
                --end;
            }
            else {
                ++start;
            }
        }
    }
    return ans;
}

// Time complexity O(n*n*log(n))
// Space complexity O(n)
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> st;
    for(int i=0; i<n-2; ++i) {
        int start = i+1, end = n-1;
        while(start<end) {
            int sum = nums[i] + nums[start] + nums[end];
            if(sum == 0) {
                st.insert(vector<int> {nums[i], nums[start], nums[end]});
                ++start;
                --end;
            }
            else if(sum > 0) {
                --end;
            }
            else {
                ++start;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
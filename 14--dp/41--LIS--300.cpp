// Longest Increasing Subsequence -- leetcode 300

// Best solution
// Time complexity O(nlogn)
// Space complexity O(size of lis)

// This will track the lcs in tiill index
// But it is not garented that lcs will end that index
// it may end earlier
int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    for(int num : nums) {
        if(temp.empty() || temp.back() < num) {
            temp.push_back(num);
        }
        else {
            int index = lower_bound(temp.begin(), temp.end(), num) - temp.begin();
            temp[index] = num;
        }
    }
    return temp.size();
}

// Best
int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;
    int n = nums.size();
    temp.push_back(nums[0]);
    for(int i=1; i<n; ++i) {
        if(temp.back() < nums[i]) {
            temp.push_back(nums[i]);
        }
        else {
            int index = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[index] = nums[i];
        }
    }
    return temp.size();
}

// Time complexity O(n*n)
// Space complexity O(n)
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), maxLen = 1;
    vector<int> dp(n, 1);
    // dp[i] --> max length subsequence which ends in i index
    for(int currIndex=1; currIndex < n; ++currIndex) {
        for(int prevIndex=0; prevIndex < currIndex; ++prevIndex) {
            if(nums[prevIndex] < nums[currIndex] && ((dp[prevIndex] + 1) > dp[currIndex])) {
                dp[currIndex] = dp[prevIndex] + 1;
            }
        }
        if(maxLen < dp[currIndex]) maxLen = dp[currIndex];
    }
    return maxLen;
}

// Time complexity O(n*n)
// Space complexity O(n*n) + O(n) Recursion stack space
int getLIS(int index, int prev, vector<int> &nums, vector<vector<int>> &dp) {
    if(index==nums.size()) return 0;
    if(dp[index][prev] != -1) return dp[index][prev];
    int pick = 0;
    if(prev==0 || nums[prev-1]<nums[index]) {
        pick = 1 + getLIS(index+1, index+1, nums, dp);
    }
    int notPick = getLIS(index+1, prev, nums, dp);
    return dp[index][prev] = max(pick, notPick);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return getLIS(0, 0, nums, dp);
}
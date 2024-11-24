// Frog Jump -- Coding Ninjas

// Geek Jump
// Memoization - top down approach
// Time complexity O(n)
// Space complexity O(2n)
// Considering recursion stack space
int solve(int index, vector<int> &height, vector<int> &dp) {
    if(index==0) return 0;
    if(index==1) return abs(height[1] - height[0]);
    if(dp[index]!=-1) return dp[index];
    int prev2 = abs(height[index] - height[index-2]) + solve(index-2, height, dp);
    int prev1 = abs(height[index] - height[index-1]) + solve(index-1, height, dp);
    return dp[index] = min(prev2, prev1);
}
int minimumEnergy(vector<int>& height, int n) {
    if(n==1) return 0;
    vector<int> dp(n, -1);
    int ans = solve(n-1, height, dp);
    return ans;
}

// Tabulation
// Time complexity O(n)
// Space complexity O(n)
int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    if(n<=2) return dp[n-1];
    for(int i=2; i<n; ++i) {
        int prev2 = dp[i-2] + abs(height[i] - height[i-2]);
        int prev1 = dp[i-1] + abs(height[i] - height[i-1]);
        dp[i] = min(prev1, prev2);
    }
    return dp[n-1];
}

// Space optimization
// Time complexity O(n)
// Space complexity O(1)
int minimumEnergy(vector<int>& height, int n) {
    int prev2 = 0;
    if(n==1) return prev2;
    int prev1 = abs(height[1] - height[0]);
    if(n==2) return prev1;
    int curr;
    for(int i=2; i<n; ++i) {
        int previousValue2 = prev2 + abs(height[i] - height[i-2]);
        int previousValue1 = prev1 + abs(height[i] - height[i-1]);
        curr = min(previousValue1, previousValue2);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// Memoization - top down approach
// Time complexity O(n)
// Space complexity O(2n)
// Considering recursion stack space
int solve(int index, vector<int>& heights, vector<int>& dp) {
    if(index==0) {
        return 0;
    }
    if(index==1) {
        return abs(heights[1]-heights[0]);
    }
    if(dp[index]!=-1) {
        return dp[index];
    }
    
    int prev2 = solve(index-2, heights, dp) + abs(heights[index]-heights[index-2]);
    int prev = solve(index-1, heights, dp) + abs(heights[index]-heights[index-1]);
    
    return dp[index] = min(prev2, prev);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    int ans = solve(n-1, heights, dp);
    return ans;
}


// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(n)
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n);
    // Initially frog is in 0-index
    dp[0] = 0;
    if(n==1) return dp[0];
    dp[1] = abs(heights[1] - heights[0]);
    if(n==2) return dp[1];

    for(int i=2; i<n; ++i) {
        int prev2 = dp[i-2] + abs(heights[i]-heights[i-2]);
        int prev = dp[i-1] + abs(heights[i]-heights[i-1]);
        dp[i] = min(prev2, prev);
    }
    return dp[n-1];
}


// Tabulation - bottom up approach
// Time complexity O(n)
// Space complexity O(1)
int frogJump(int n, vector<int> &heights) {
    int prev2 = 0;
    if(n==1) return prev2;
    int prev1 = abs(heights[1]-heights[0]);
    if(n==2) return prev1;
    int curr;
    for(int index=2; index<n; ++index) {
        int one = prev1 + abs(heights[index]-heights[index-1]);
        int two = prev2 + abs(heights[index]-heights[index-2]);
        curr = min(one, two);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
// Missing Number in ana array -- leetcode 268
// Solution 1 & 2 are best

// Solution 1
// Best solution
// Time complexity O(n)
// Space complexity O(1)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = (ans^nums[i]^(i+1));
    }
    return ans;
}

// Solution 2
// Best solution
// Time complexity O(n)
// Space complexity O(1)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans += (i+1-nums[i]);
    }
    return ans;
}

// Solution 3
// Hashing Solution
// Time complexity O(n)
// Space complexity O(n)
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    vector<int> freq(n+1, 0);
    for(int i=0; i<n; ++i) {
        freq[nums[i]]++;
    }
    for(int i=0; i<=n; ++i) {
        if(freq[i]==0) {
            return i;
        }
    }
    return -1;
}

// Solution 4
// Time complexity O(nlogn)
// Space complexity O(1)
int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i=0; i<n; ++i) {
        if(nums[i]!=i)
            return i;
    }
    return n;
}
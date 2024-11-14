// leetcode 128
// Longest Consecutive Sequence

// Brute force
// Time complexity O(n^3)
// Space complexity O(1)
bool isPresent(int target, vector<int>& nums) {
    for(int element:nums) {
        if(element==target) {
            return true;
        }
    }
    return false;
}
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    int maxCount  = 1;
    for(int i=0; i<n; ++i) {
        int count = 1;
        int num = nums[i];
        while(isPresent(num + 1, nums)) {
            ++count;
            ++num;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

// Sorting
// Time complexity O(nlogn)
// Space O(1)
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    sort(nums.begin(), nums.end());
    int maxCount = 1, count = 1, lastElement = INT_MIN;
    for(int i=0; i<n; ++i) {
        if(lastElement+1==nums[i]) ++count;
        else if(lastElement==nums[i]) continue;
        else count = 1;
        lastElement = nums[i];
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

// Using unordered_set
// Time complexity O(n)
// Space complexity O(n)
// Uisng recursion
int findCount(int num, unordered_set<int>& s) {
    if(s.find(num)!=s.end()) {
        return 1 + findCount(num+1, s);
    }
    return 0;
}
int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    unordered_set<int>s;
    for(int i=0; i<n; ++i) {
        s.insert(nums[i]);
    }
    int maxCount = 1, count, num;
    for(int element:s) {
        num = element - 1;
        if(s.find(num)==s.end()) {
            count = findCount(element, s);
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}
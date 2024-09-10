// 10
// leetcode 287
// Find duplicate number
// Time complexity O(n)
// Space complexity O(n)
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int>s;
    for(int i=0; i<n; ++i) {
        if(s.find(nums[i])!=s.end()) {
            return nums[i];
        }
        s.insert(nums[i]);
    }
    return -1;
}

// Time complexity O(n)
// Space complexity O(n)
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    vector<bool> hash(n, false);
    for(int i=0; i<n; ++i) {
        if(hash[nums[i]]) {
            return nums[i];
        }
        hash[nums[i]] = true;
    }
    return -1;
}

// Time complexity O(n)
// Space complexity O(1)
// Best approach
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n<=2) return nums[0];
    int slow = nums[0], fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow!=fast);
    fast = nums[0];
    while(slow!=fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
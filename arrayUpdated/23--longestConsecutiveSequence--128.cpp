// Longest Consecutive Sequence -- leetcode 128

// Array can be empty and array can have duplicate numbers
// Time complexity O(nlogn)
// Space complexity O(1)
int longestConsecutive(vector<int>& nums) {
    int n = nums.size(), lastSmallest = INT_MIN, count, maxCount = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; ++i) {
        if(lastSmallest+1 == nums[i]) {
            ++count;
        }
        else if(lastSmallest != nums[i]){
            count = 1;
        }
        lastSmallest = nums[i];
        maxCount = max(count, maxCount);
    }
    return maxCount == INT_MIN ? 0 : maxCount;
}


// Time complexity O(n)
// Space complexity O(n)
// Clean solution
int longestConsecutive(vector<int>& nums) {
    unordered_set<int>us;
    for(int num:nums) {
        us.insert(num);
    }
    int maxCount = 0;
    for(int num:us) {
        int number = num - 1;
        auto itr = us.find(number);
        if(itr == us.end()) {
            int count = 1;
            int next = num + 1;
            while(us.find(next) != us.end()) {
                ++count;
                ++next;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}
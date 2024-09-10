// (We can't check if an array is sorted or not in logN complexity)
// Coding Ninjas
int isSorted(int n, vector<int> a) {
    if(n<=1) return 1;
    for(int i=1; i<n; ++i) {
        if(a[i]<a[i-1]) return 0;
    }
    return 1;
}


// leetcode 1752 ***
// Time complexity O(n)
// Space complexity O(1)
// We can't do this in O(logn) beacuse we can't not eliminate one half in each step
// [6 10 6]
// edge case
bool check(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i=1; i<n; ++i) {
        if(nums[i-1] > nums[i]) ++count;
    }
    if(count == 0) return true;
    if(count == 1) return nums.front() >= nums.back(); // equal for handling duplicate element
    return false;
}
// 24
// Remove duplicate from sorted array -- leetcode 26

// Time complexity O(n)
// Space complexity O(n)
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int temp[n];
    temp[0] = nums[0];
    int index = 1;
    for(int i=1; i<n; ++i) {
        if(nums[i-1]!=nums[i]) {
            temp[index++] = nums[i];
        }
    }
    for(int i=0; i<index; ++i) {
        nums[i] = temp[i];
    }
    return index;
}

// Time complexity O(n)
// Space complexity O(1)
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int index = 1;
    for(int i=1; i<n; ++i) {
        if(nums[i-1]!=nums[i]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}
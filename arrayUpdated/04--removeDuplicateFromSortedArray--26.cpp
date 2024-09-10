// Time complexity O(n)
// Space complexity O(1)
// best approach
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int index = 1; // index is the updated array size
    // updated array should have at least one element
    for(int i=1; i<n; ++i) {
        if(nums[i-1]!=nums[i]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}


// Time complexity O(n)
// Space complexity O(1)
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int index = 0;
    for(int i=0; i<n-1; ++i) {
        if(nums[i]!=nums[i+1]) {
            nums[index++] = nums[i];
        }
    }
    nums[index] = nums[n-1];
    return (index+1);
}

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
// Space complexity O(n)
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int temp[n];
    int index = 0;
    for(int i=0; i<n-1; ++i) {
        if(nums[i]!=nums[i+1]) {
            temp[index++] = nums[i];
        }
    }

    temp[index] = nums[n-1];

    for(int i=0; i<=index; ++i) {
        nums[i] = temp[i];
    }
    return (index+1);
}
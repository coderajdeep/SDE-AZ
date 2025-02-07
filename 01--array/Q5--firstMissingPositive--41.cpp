// First Missing Positive -- leetcode 41
// Time complexity O(n)
// Space complexity O(n)

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    vector<bool> arr(n+1, false);
    for(int num : nums) {
        if(num>0 && num<=n) {
            arr[num] = true;
        }
    }
    for(int i=1; i<=n; ++i) {
        if(!arr[i]) {
            return i;
        }
    }
    return (n+1);
}

// Best solution
// Time complexity O(n)
// Space complexity O(1)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    bool isOnePresent = false;
    for(int i=0; i<n; ++i) {
        if(nums[i] == 1) isOnePresent = true;
        // Answer can be between 1 to (n+1) [n+1] will be handle later
        // so if the numbers is not in range then convert it into 1
        if(nums[i]<=0 || nums[i]>n) {
            nums[i] = 1;
        }
    }
    // is 1 is not present then 1 is the answer
    if(!isOnePresent) return 1;

    // if any number present then mark the indexed value with same but negative number
    // after this operation, if any value > 0 then this will be the answer
    // also sorted the n into o the index
    for(int i=0; i<n; ++i) {
        int value = abs(nums[i]);
        if(value == n) {
            nums[0] = -abs(nums[0]);
        }
        else {
            nums[value] = -abs(nums[value]);
        }
    }
    for(int i=1; i<n; ++i) {
        if(nums[i] > 0) return i;
    }
    if(nums[0] > 0) return n;
    // if number is not between 1 to n then answer will be n+1
    else return (n+1);
}
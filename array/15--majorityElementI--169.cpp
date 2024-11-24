// leetcode 169
// Majority element (n/2)
// Time complexity O(n)
// Space complexity O(n)
// TLE
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_multiset<int>ms;
    for(int i=0; i<n; ++i) {
        ms.insert(nums[i]);
        if(ms.count(nums[i])>(n/2)) return nums[i];
    }
    return -1;
}

// Time complexity O(nlogn)
// Space complexity O(1)
// Surprisingly this pass all the test case
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int mid = n/2;
    return nums[mid];
}

// Time complexity O(n)
// Space complexity O(1)
// If it's not guaranteed that majority element will exist
// Then we need to check this  
int isMajorityElement(int element, int n, int* arr) {
    int count = 0;
    for(int i=0; i<n; ++i) {
        if(element==arr[i]) {
            ++count;
            if(count>(n/2)) {
                return true;
            }
        }
    }
    return false;
}
int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int count = 0, index;
    for(int i=0; i<n; ++i) {
        if(!count) {
            index = i;
            ++count;
        }
        else if(nums[index]==nums[i]) ++count;
        else if(nums[index]!=nums[i]) --count;
    }
    return nums[index];
}
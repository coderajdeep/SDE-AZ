// leetcode 31
// Next permutation
// Time complexity O(n)
// Space complexity O(1)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int start, int end, vector<int>& nums) {
    while(start<end) {
        swap(nums[start++], nums[end--]);
    }
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = -1;
    for(int i=n-2; i>=0; --i) {
        if(nums[i]<nums[i+1]) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        reverseArray(0, n-1, nums);
        return;
    }
    for(int i=n-1; i>index; --i) {
        if(nums[i]>nums[index]) {
            swap(nums[index], nums[i]);
            break;
        }
    }
    reverseArray(index+1, n-1, nums);
}
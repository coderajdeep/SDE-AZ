// 27
// Rotate Array (Clockwise or right rotation) -- leetcode 189

// Time complexity O(3*n) ~ O(n)
// Space complexity O(1)
void swapNumbers(int& a, int& b) {
    a = (a+b);
    b = (a-b);
    a = (a-b);
}
void reverseArray(int start, int end, vector<int>& nums) {
    while(start<end) {
        swapNumbers(nums[start++], nums[end--]);
    }
}
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n==k || n==1) return;
    if(k>n) k = (k % n);
    reverseArray(0, n - k - 1, nums);
    reverseArray(n - k, n - 1, nums);
    reverseArray(0, n - 1, nums);
} 
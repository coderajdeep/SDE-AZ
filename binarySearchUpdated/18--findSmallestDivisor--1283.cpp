// Find the smallest divisor -- leetcode 1283

// Time complexity O(log(max element in array) * n) + O(n)
// Space complexity O(1)
long getSum(vector<int>& nums, int threshold, int divisor) {
    long sum = 0;
    for(int num : nums) {
        sum += ceil((double)num/divisor);
    }
    return sum;
}
int getMaxNum(vector<int>& nums) {
    int maxValue = INT_MIN;
    for(int num : nums) {
        maxValue = max(num, maxValue);
    }
    return maxValue;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = getMaxNum(nums), mid, ans;
    while(low <= high) {
        mid = low + (high - low) / 2;
        long sum = getSum(nums, threshold, mid);
        if(sum <= threshold) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return ans;
}
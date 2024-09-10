// Time complexity O(n)
// Space complexity O(n)

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size(), evenIndex = 0, oddIndex = 1;
    vector<int> ans(n);
    for(int i=0; i<n; ++i) {
        if(nums[i]>=0) {
            ans[evenIndex] = nums[i];
            evenIndex += 2;
        }
        else {
            ans[oddIndex] = nums[i];
            oddIndex += 2;
        }
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
// If the number of even and odd elements are not equal
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size(), evenIndex = 0, oddIndex = 1;
    vector<int> even, odd, ans(n);
    even.reserve(n);
    odd.reserve(n);
    for (int i = 0; i < n; ++i) {
        if (nums[i] >= 0) {
            even.push_back(nums[i]);
        }
        else {
            odd.push_back(nums[i]);
        }
    }
    int evenSize = even.size();
    int oddSize = odd.size();
    int minSize = min(evenSize, oddSize);
    for (int i = 0; i < minSize; ++i) {
        ans[2 * i] = even[i];
        ans[2 * i + 1] = odd[i];
    }
    vector<int>& remainingNumbers = evenSize > oddSize ? even : odd;
    int remainingNumbersStartIndex = minSize;
    for (int i = minSize * 2; i < n; ++i) {
        ans[i] = remainingNumbers[remainingNumbersStartIndex++];
    }
    return ans;
}
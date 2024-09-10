// Sum of subarray ranges -- leetcode 2104

// Time complexity O(n)
// Space complexity O(n)
void getNSE(vector<int>& nums, vector<int>& left, vector<int>& right) {
    int n = nums.size();
    stack<int> stkL, stkR;

    for(int i=0; i<n; ++i) {
        while(!stkL.empty() && nums[stkL.top()] >= nums[i]) {
            stkL.pop();
        }
        if(!stkL.empty()) {
            left[i] = stkL.top();
        }
        while(!stkR.empty() && nums[stkR.top()] > nums[n-1-i]) {
            stkR.pop();
        }
        if(!stkR.empty()) {
            right[n-1-i] = stkR.top();
        }
        stkL.push(i);
        stkR.push(n-1-i);
    }
}
void getNGE(vector<int>& nums, vector<int>& left, vector<int>& right) {
    int n = nums.size();
    stack<int> stkL, stkR;

    for(int i=0; i<n; ++i) {
        while(!stkL.empty() && nums[stkL.top()] <= nums[i]) {
            stkL.pop();
        }
        if(!stkL.empty()) {
            left[i] = stkL.top();
        }
        while(!stkR.empty() && nums[stkR.top()] < nums[n-1-i]) {
            stkR.pop();
        }
        if(!stkR.empty()) {
            right[n-1-i] = stkR.top();
        }
        stkL.push(i);
        stkR.push(n-1-i);
    }
}
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftNSE(n, -1), rightNSE(n, -1), leftNGE(n, -1), rightNGE(n, -1);
    getNSE(nums, leftNSE, rightNSE);
    getNGE(nums, leftNGE, rightNGE);
    long long ans = 0;
    for(int i=0; i<n; ++i) {
        int leftValueNSE = ((leftNSE[i] == -1) ? i + 1 : i - leftNSE[i]);
        int rightValueNSE = ((rightNSE[i] == -1) ? n - i : rightNSE[i] - i);
        int leftValueNGE = ((leftNGE[i] == -1) ? i + 1 : i - leftNGE[i]);
        int rightValueNGE = ((rightNGE[i] == -1) ? n - i : rightNGE[i] - i);
        ans += ((long)leftValueNGE * (long)rightValueNGE * (long)nums[i] - (long)leftValueNSE * (long)rightValueNSE * (long)nums[i]);
    }
    return ans;
}
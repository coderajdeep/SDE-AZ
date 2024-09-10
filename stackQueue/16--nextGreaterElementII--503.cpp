// Next greater element -- leetcode 503
// https://leetcode.com/problems/next-greater-element-ii/solutions/3390699/optimized-solution-easy-c-stack-implementation-st/

// [1, 2, 3, 4, 6, 5]
// Corner case
// Time complexity O(2*n)
// Time complexity O(2*n)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> stk;
    for(int i=n-2; i>=0; --i) {
        stk.push(nums[i]);
    }
    for(int i=n-1; i>=0; --i) {
        while(!stk.empty() && stk.top()<=nums[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            ans[i] = stk.top();
        }
        stk.push(nums[i]);
    }
    return ans;
}
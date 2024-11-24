// Next smalletr element  -- InterviewBit

// https://www.interviewbit.com/problems/nearest-smaller-element/
// Time complexity O(n)
// Space complexity O(n)
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> stk;
    int n = A.size();
    vector<int> ans(n, -1);
    for(int i=0; i<n; ++i) {
        while(!stk.empty() && stk.top()>=A[i]) {
            stk.pop();
        }
        if(!stk.empty()) {
            ans[i] = stk.top();
        }
        stk.push(A[i]);
    }
    return ans;
}

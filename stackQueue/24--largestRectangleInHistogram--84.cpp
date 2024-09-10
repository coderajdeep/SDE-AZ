// Largest Rectangle in histogram -- leetcode 84

// Brute force
// Time complexity O(n^2)
// Space complexity O(1)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int start, end, ans = 0;
    for(int i=0; i<n; ++i) {
        for(start=i; (start>=0 && heights[start]>=heights[i]); --start) {}
        for(end=i; (end<n && heights[end]>=heights[i]); ++end) {}
        ans = max(ans, (end-start-1)*heights[i]);
    }
    return ans;
}

// Using stack
// Time complexity O(n)
// Space complexity O(n)
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int prev[n];
    int next[n];
    stack<int> stk1, stk2;
    int start = 0, end = n-1, ans = 0;

    while(start<n && end>=0) {
        while(!stk1.empty() && heights[stk1.top()]>=heights[start]) {
            stk1.pop();
        }
        if(stk1.empty()) {
            prev[start] = -1;
        }
        else {
            prev[start] = stk1.top();
        }
        stk1.push(start);

        while(!stk2.empty() && heights[stk2.top()]>=heights[end]) {
            stk2.pop();
        }
        if(stk2.empty()) {
            next[end] = n;
        }
        else {
            next[end] = stk2.top();
        }
        stk2.push(end);
        ++start;
        --end;
    }
    for(int i=0; i<n; ++i) {
        ans = max(ans, ((next[i]-prev[i]-1)*heights[i]));
    }
    return ans;
}

// Modular code
// Time complexity O(n)
// Space complexity O(n)
void getPrevNextSmaller(vector<int>& heights, vector<int>& prev, vector<int>& next) {
    stack<int> stkPrev, stkNext;
    int n = heights.size();
    for(int i=0; i<n; ++i) {
        while(!stkPrev.empty() && heights[stkPrev.top()] >= heights[i]) {
            stkPrev.pop();
        }
        if(stkPrev.empty()) {
            prev[i] = 0;
        }
        else {
            prev[i] = stkPrev.top() + 1;
        }
        while(!stkNext.empty() && heights[stkNext.top()] >= heights[n-1-i]) {
            stkNext.pop();
        }
        if(stkNext.empty()) {
            next[n-1-i] = n - 1;
        }
        else {
            next[n-1-i] = stkNext.top() - 1;
        }
        stkPrev.push(i);
        stkNext.push(n-1-i);
    }
}
int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> prev(n, 0), next(n, 0);
    getPrevNextSmaller(heights, prev, next);
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = max(ans, (next[i] - prev[i] + 1) * heights[i]);
    }
    return ans;
}
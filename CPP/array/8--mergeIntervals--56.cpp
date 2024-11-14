// leetcode 56
// Merge intervals
// Time Complexity O(nlogn) + O(n) ~ O(nlogn)
// Space complexity O(1)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    if(n==1) return intervals;
    vector<vector<int>> ans;
    int start = intervals[0][0], end = intervals[0][1];
    for(int i=1; i<n; ++i) {
        if(intervals[i][0]<=end) {
            if(end<intervals[i][1]) {
                end = intervals[i][1];
            }
        }
        else {
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }
    ans.push_back({start, end});
    return ans;
}

// Time Complexity O(nlogn) + O(n) ~ O(nlogn)
// Space complexity O(1)
// Clean solution
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if(n==1) return intervals;
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for(int i=0; i<n; ++i) {
        if(ans.empty() || (ans.back()[1] < intervals[i][0])) {
            ans.push_back(intervals[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
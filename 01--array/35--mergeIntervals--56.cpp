// Time complexity O(nlogn)
// Space complexity O(n) [Space is used for storing the answer]
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0], end = intervals[0][1];
        for(int i=1; i<n; ++i) {
            if(intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
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
};
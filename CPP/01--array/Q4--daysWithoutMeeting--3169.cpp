// Time complexity O(nlogn)
// Space complexity O(n) -- for storing answer
int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());
    int count = meetings[0][0] - 1, end = meetings[0][1], n = meetings.size();
    for(int i=1; i<n; ++i) {
        if(end>=meetings[i][0]) {
            end = max(end, meetings[i][1]);
        }
        else {
            count += (meetings[i][0] - end - 1);
            end = meetings[i][1];
        }
    }
    count += (days-end);
    return count;
}
// Time complexity O(nlogn)
// Space complexity O(n)

static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
    return p1.second<p2.second;
} 
int maxMeetings(int n, int start[], int end[]) {
    vector<pair<int, int>> arr(n);
    for(int i=0; i<n; ++i) {
        arr[i] = pair<int, int> {start[i], end[i]};
    }
    sort(arr.begin(), arr.end(), comp);
    int endTime = arr[0].second;
    int count = 1;
    for(int i=1; i<n; ++i) {
        if(arr[i].first>endTime) {
            endTime = arr[i].second;
            ++count;
        }
    }
    return count;
}
// Solution 1
// Best solution
// Time complexity O(n+m)
// Space complexity O(1)
int rowWithMax1s(vector<vector<int> > &arr) {
    int n = arr.size(), m = arr[0].size();
    int r = 0, c = m-1, row = -1, col = m-1;
    while(r<n && c>=0) {
        if(arr[r][c]==1) --c;
        else ++r;
        
        if(c<col) {
            row = r;
            col = c;
        }
        if(c==-1) break;
    }
    return row;
}

// Solution 2
// Time complexity O(nlog2m)
// Space complexity O(1)
int rowWithMax1s(vector<vector<int> > &arr) {
    int n = arr.size(), m = arr[0].size(), ans = -1, ones = -1;
    for(int i=0; i<n; ++i) {
        int idx = (lower_bound(arr[i].begin(), arr[i].end(), 1) - arr[i].begin());
        if(idx != m && arr[i][idx] == 1) {
            if(ones < (m - idx)) {
                ones = m - idx;
                ans = i;
                if(ones == m) {
                    break;
                }
            }
        }
    }
    return ans;
}

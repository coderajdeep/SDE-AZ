// Path with minimum effort -- leetcode 1631
// Time complexity O(4*n*m*log(n*m))
// Space complexity O(n*m)
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    dist[0][0] = 0;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    while(!pq.empty()) {
        pair<int, pair<int, int>> node = pq.top();
        pq.pop();
        int x = node.second.first;
        int y = node.second.second;
        for(int i=0; i<4; ++i) {
            int a = x + dx[i];
            int b = y + dy[i];
            if(a>=0 && a<n && b>=0 && b<m) {
                int diff = abs(heights[a][b]-heights[x][y]);
                int maxDiff = max(diff, dist[x][y]);
                if(maxDiff < dist[a][b]) {
                    dist[a][b] = maxDiff;
                    pq.push({maxDiff, {a, b}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
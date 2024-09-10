// Plain BFS
// As the weight for every edge is equal
// So bfs is better than dijkstra
// Time complexity O(n*n*8)
// Space complexity O(n*n)
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    if(grid[0][0]==0) {
        dist[0][0] = 1;
        q.push({0, 0});
    }
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                int r = x + i;
                int c = y + j;
                // we can avoid this when x==0 && y==0
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && (dist[x][y]+1<dist[r][c])) {
                    dist[r][c] = dist[x][y]+1;
                    q.push({r, c});
                }
            }
        }
    }
    return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
}

// Shortest path in binary matrix -- leetcode 1091
// Time complexity (n*n*8*2 log(n))
// Using dijkstra's algorithm
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int size = n * n;
    if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
    // Index in dist vector
    // row*n + col
    vector<int> dist(size, INT_MAX);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[0] = 1;
    pq.push({1, {0, 0}});
    while(!pq.empty()) {
        pair<int, pair<int, int>> pr = pq.top();
        pq.pop();
        int i = pr.second.first;
        int j = pr.second.second;
        for(int x=-1; x<=1; ++x) {
            for(int y=-1; y<=1; ++y) {
                if(!(x==0 && y==0)) {
                    int r = i+x;
                    int c = j+y;
                    int source_index = i*n + j;
                    int dest_index = r*n + c;
                    if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && (dist[source_index]+1 < dist[dest_index])) {
                        dist[dest_index] = dist[source_index]+1;
                        pq.push({dist[dest_index], {r, c}});
                    }
                }
            }
        }
    }
    return dist[size-1]!=INT_MAX ? dist[size-1] : -1;
}

// Similar to the above approach
// Clean code
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    if(grid[0][0]==0) {
        dist[0][0] = 1;
        pq.push({dist[0][0], {0, 0}});
    }
    while(!pq.empty()) {
        pair<int, pair<int, int>> node = pq.top();
        pq.pop();
        int x = node.second.first;
        int y = node.second.second;
        for(int i=-1; i<=1; ++i) {
            for(int j=-1; j<=1; ++j) {
                int r = x + i;
                int c = y + j;
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0 && (dist[x][y]+1<dist[r][c])) {
                    dist[r][c] = dist[x][y]+1;
                    pq.push({dist[r][c], {r, c}});
                }
            }
        }
    }
    return dist[n-1][n-1] == INT_MAX ? -1 : dist[n-1][n-1];
}
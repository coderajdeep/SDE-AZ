// Bellman Ford Algorithm -- Works on graph having negative cycle
// Time complexity O(N * E)
// Can be used to detect the existance of negative cycle
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;
    for(int i=0; i<n-1; ++i) {
        for(vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}
// Find city with smaller number of Neighbors -- leetcode 1334
// Time complexity O(n^3)
// Space complexity O(n^2)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adj(n, vector<int>(n, INT_MAX));
    for(vector<int> edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for(int k=0; k<n; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i==j) {
                    adj[i][j] = 1;
                }
                else if (adj[i][k] < INT_MAX && adj[k][j] < INT_MAX) {
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    int minCityCount = INT_MAX;
    int ansCity = -1;
    for(int i=n-1; i>=0; --i) {
        int cnt = 0;
        for(int j=0; j<n; ++j) {
            if(adj[i][j]<=distanceThreshold && i!=j) ++cnt;
        }
        if(cnt < minCityCount) {
            minCityCount = cnt;
            ansCity = i;
        }
    }
    return ansCity;
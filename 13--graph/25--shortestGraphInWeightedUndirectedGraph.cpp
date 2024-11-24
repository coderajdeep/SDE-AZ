// Shortest Path in Weighted undirected graph -- Geeks
// Time complexity O(ELogV) + O(V)
// Space complexity O(ELogV) + O(V)
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n+1, INT_MAX), parent(n+1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    parent[1] = 1;
    
    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        int u = node.second;
        for(pair<int, int> p : adj[u]) {
            int v = p.first;
            int dis = p.second;
            if(dist[u]+dis < dist[v]) {
                dist[v] = dist[u] + dis;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    if(parent[n]==-1) return vector<int> {-1};
    vector<int> ans;
    int node = n;
    while(parent[node]!=node) {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(node);
    // This is not right
    // Just for the geeks for geeks answer, I have added the below line
    ans.push_back(dist[n]);
    reverse(ans.begin(), ans.end());
    return ans;
}
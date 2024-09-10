// Floyd Warshall Algorithm 
// As the given question, only negative edge exist and negative cycle does not exist
// And it was single source shortest path, we can solve this using Dijkstra
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n+1];
    for(vector<int> e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        int u = p.second;
        pq.pop();
        for(pair<int, int> pr : adj[u]) {
            int v = pr.first;
            int dis = pr.second;
            if(dist[u]+dis<dist[v]) {
                dist[v] = dis + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
    return dist[dest];
}


// Floyd Warshall Algorithm
// Time complexity O(n^3)
// Space complexity O(n^2)
int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 1e9));
    for(vector<int> e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
       adjMatrix[u][v] = w;
    }
    for(int viaNode=1; viaNode<=n; ++viaNode) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(i==j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    int viaDist = (adjMatrix[i][viaNode]!=1e9 && adjMatrix[viaNode][j]!=1e9) ? (adjMatrix[i][viaNode] + adjMatrix[viaNode][j]) : 1e9;
                    adjMatrix[i][j] = min(adjMatrix[i][j], viaDist);
                }
            }
        }
    }
    return adjMatrix[src][dest];
}
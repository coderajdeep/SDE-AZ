// Sortest path in Undirected and Unweighted graph 
// Time complexity O(V+2*E)
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    vector<int> adj[n];
    for(vector<int> edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> dist(n, -1);
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(dist[v]==-1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            else if(dist[u]+1<dist[v] ) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
vector<int> bfs(int u, int V, vector<int> *adj) {
    vector<bool> visited(V, false);
    vector<int> ans;
    queue<int> q;
    q.push(u);
    visited[u] = true;
    
    while(!q.empty()) {
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for(int v : adj[u]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    
    return ans;
}
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    return bfs(0, V, adj);
}
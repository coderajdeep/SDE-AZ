void dfs(int u, vector<int> *adj, vector<bool> &visited, vector<int> &ans) {
    ans.push_back(u);
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, adj, visited, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    vector<int> ans;
    dfs(0, adj, visited, ans);
    return ans;
}
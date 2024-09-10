// Detect cycle using BFS
// Time complexity O(V+E)
// Space complexity O(V+E)
bool dfs(int node, int parent, vector<int> *adj, vector<bool> &visited) {
    visited[node] = true;
    for(int v : adj[node]) {
        if(!visited[v] && dfs(v, node, adj, visited)) {
            return true;
        }
        if(visited[v] && v != parent) return true;
    }
    return false;
}
bool detectCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for(int i=1; i<V; ++i) {
        if(!visited[i] && dfs(i, -1, adj, visited)) return true;
    }
    return false;
}

// Using DFS
// Time complexity O(V+E)
// Space complexity O(V+E) + Recursion stack space O(V)
bool dfs(int node, int parent, vector<int> *adj, vector<bool> &visited) {
    visited[node] = true;
    for(int v : adj[node]) {
        if(!visited[v]) {
            if(dfs(v, node, adj, visited)) {
                return true;
            }
        }
        else if(v != parent) {
            return true;
        }
    }
    return false;
}
bool detectCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
    for(int i=0; i<V; ++i) {
        if(!visited[i] && dfs(i, -1, adj, visited)) {
            return true;
        }
    }
    return false;
}
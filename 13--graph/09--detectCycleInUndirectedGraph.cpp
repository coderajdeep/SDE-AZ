// Detect cycle using BFS
// Time complexity O(V+E)
// Space complexity O(V+E)
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool bfs(int source, bool *visited, vector<int> *adj) {
        queue<pair<int, int>> q; // node, parent
        visited[source] = true;
        q.push({source, -1});
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            int parent = p.second;
            int u = p.first;
            q.pop();
            for(int v:adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push({v, u});
                }
                else if(visited[v] && v!=p.second) return true;
                
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        bool visited[V];
        for(int i=0; i<V; ++i) visited[i] = false;
        for(int i=0; i<V; ++i) {
            if(!visited[i] && bfs(i, visited, adj)) {
                return true;
            } 
        }
        return false;
    }
};



// Using DFS
// Time complexity O(V+E)
// Space complexity O(V+E) + Recursion stack space O(V)
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
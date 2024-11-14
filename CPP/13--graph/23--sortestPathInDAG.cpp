// Shortest path in directed acyclic graph

void topoSort(int u, vector<bool> &visited, vector<pair<int, int>> *adj, stack<int> &stk) {
    visited[u] = true;
    for(pair<int, int> p : adj[u]) {
        int v = p.first;
        if(!visited[v]) {
            topoSort(v, visited, adj, stk);
        }
    }
    stk.push(u);
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n];
    for(vector<int> edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    vector<bool> visited(n, false);
    stack<int> stk;
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            topoSort(i, visited, adj, stk);
        }
    }
    while(!stk.empty() && stk.top()!=0) stk.pop();
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        for(pair<int, int> p : adj[u]) {
            int v = p.first;
            int dis = p.second;
            if(dist[u]+dis<dist[v]) {
                dist[v] = dist[u]+dis;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        if(dist[i]==INT_MAX) {
            dist[i] = -1;
        }
    }
    return dist;
}

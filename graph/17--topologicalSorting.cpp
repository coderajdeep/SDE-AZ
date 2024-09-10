// Using DFS
// Time complexity O(V+E)
// Space Complexity O(V)
void dfs(int u, vector<bool> &visited, stack<int> &stk, vector<int> *adj) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, visited, stk, adj);
        }
    }
    stk.push(u);
}

vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];
    for(int i=0; i<edges; ++i) {
        adj[graph[i][0]].push_back(graph[i][1]);
    }
    vector<bool> visited(nodes, false);
    stack<int> stk;
    for(int i=0; i<nodes; ++i) {
        if(!visited[i]) dfs(i, visited, stk, adj);
    }
    vector<int> ans(nodes);
    for(int i=0; i<nodes; ++i) {
        ans[i] = stk.top();
        stk.pop();
    }
    return ans;
}

// Using BFS
// Time complexity O(V+E)
// Space Complexity O(V)
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) {
    vector<int> adj[nodes];
    vector<int> indegree(nodes, 0);
    for(int i=0; i<edges; ++i) {
        adj[graph[i][0]].push_back(graph[i][1]);
        indegree[graph[i][1]]++;
    }
    vector<int> ans(nodes);
    int index = 0;
    queue<int> q;
    for(int i=0; i<nodes; ++i) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        ans[index++] = u;
        q.pop();
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
            }
        }
    }
    return ans;
}
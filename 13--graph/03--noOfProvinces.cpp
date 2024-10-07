// Number of provinces
// Time complexity O(V+E)

void dfs(int u, vector<vector<int>>& graph, vector<bool> &visited) {
    visited[u] = true;
    for(int v : graph[u]) {
        if(!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}

void bfs(int u, vector<vector<int>>& graph, vector<bool> &visited) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

vector<vector<int>> buildGraph(vector<vector<int>> &roads, int n) {
    vector<vector<int>> graph(n);
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            // i!=j
            // this is for self loop prevention
            if(i != j && roads[i][j]==1) {
                graph[i].push_back(j);
            }
        }
    }
    return graph;
}

int findNumOfProvinces(vector<vector<int>> &roads, int n) {
    vector<bool> visited(n, false);
    vector<vector<int>> graph = buildGraph(roads, n);
    int count = 0;
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            ++count;
            bfs(i, graph, visited);
            // dfs(i, graph, visited);
        }
    }
    return count;
}
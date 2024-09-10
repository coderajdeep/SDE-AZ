// Print Adjacency List
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for(int i=0; i<n; ++i) graph[i].push_back(i);
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}
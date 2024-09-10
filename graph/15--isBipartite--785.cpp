// Using DFS
bool dfs(int u, int color, vector<int> &visited, vector<vector<int>>& graph) {
    visited[u] = color;
    int adjColor = (color == 1 ? 0 : 1);
    for(int v : graph[u]) {
        if(visited[v]==-1) {
            if(!dfs(v, adjColor, visited, graph)) return false;
        }
        else if(visited[v] == color) {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int v = graph.size();
    vector<int> visited(v, -1);
    for(int i=0; i<v; ++i) {
        if(visited[i]==-1 && !dfs(i, 0, visited, graph)) return false;
    }
    return true;
}
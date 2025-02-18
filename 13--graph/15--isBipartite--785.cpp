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

// Using BFS
// Time complexity O(E+V)
// Space complexity O(E+V)
class Solution {
private:
    bool bfs(int node, vector<char> &visited, vector<vector<int>> &graph) {
        queue<int> q;
        q.push(node);
        visited[node] = 'a';
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : graph[u]) {
                if(visited[v]=='#') {
                    q.push(v);
                    visited[v] = visited[u]=='a' ? 'b' : 'a';
                }
                else if(visited[v]==visited[u]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> visited(n, '#');
        for(int i=0; i<n; ++i) {
            if(visited[i]=='#') {
                if(!bfs(i, visited, graph)) {
                    return false;
                }
            } 
        }
        return true;
    }
};
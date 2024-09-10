// Number of provinces -- leetcode 547
// Time complexity O(E+V) + O(V*V) for creating the adjancy metrix
class Solution {
public:
    vector<vector<int>> getAdjancyList(int v, vector<vector<int>>& isConnected) {
        vector<vector<int>> graph(v);
        for(int i=0; i<v; ++i) {
            for(int j=0; j<v; ++j) {
                if(i!=j && isConnected[i][j]==1) {
                    graph[i].push_back(j);
                }
            }
        }
        return graph;
    }
    void dfs(int u, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[u] = true;
        for(int v : graph[u]) {
            if(!visited[v]) {
                dfs(v, graph, visited);
            }
        }
    }
    // If we use this then we don't need adjacency list
    void dfs2(int u, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[u] = true;
        int size = graph[u].size();
        for(int v=0; v<size; ++v) {
            if(graph[u][v]==1 && !visited[v]) {
                dfs2(v, graph, visited);
            }
        }
    }
    void bfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : graph[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    // If we use this then we don't need adjacency list
    void bfs2(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int size = graph[u].size();
            for(int v=0; v<size; ++v) {
                if(graph[u][v]==1 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        // for dfs2 and bfs2, we don't need this
        // vector<vector<int>> graph = getAdjancyList(v, isConnected);
        vector<bool> visited(v, false);
        int count = 0;
        for(int i=0; i<v; ++i) {
            if(!visited[i]) {
                ++count;
                dfs2(i, isConnected, visited);
            }
        }
        return count;
    }
};
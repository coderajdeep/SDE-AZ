// Time complexity O(2*ElogE)
// Space complexity O(V+E)
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<bool> visited(V, false);
    pq.push({0, 0});
    int mstSum = 0;
    
    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        int w = node.first;
        int u = node.second;
        if(!visited[u]) {
            visited[u] = true;
            mstSum += w;
            for(vector<int> pr : adj[u]) {
                int v = pr[0];
                int wt = pr[1];
                if(!visited[v]) {
                    pq.push({wt, v});
                }
            }
        }
    }
    return mstSum;
}
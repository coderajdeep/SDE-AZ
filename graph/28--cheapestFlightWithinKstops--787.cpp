// Time complexity O(E*logN) 
// E : flights.size()
// Space complexity O(E+V) + O(V)
// Edge case : [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// n = 4, src = 0, dst = 3
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int, int>> adj[n];
    for(vector<int> flight : flights) {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // stop , dist, node
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    pq.push({0, {0, src}});

    while(!pq.empty()) {
        pair<int, pair<int, int>> node = pq.top();
        pq.pop();
        int stop = node.first;
        int dis = node.second.first;
        int u = node.second.second;
        if(stop<=k) {
            for(pair<int, int> p : adj[u]) {
                int v = p.first;
                int v_dis = p.second;
                if(v_dis+dis<dist[v]) {
                    dist[v] = v_dis + dis;
                    pq.push({stop+1, {dist[v], v}});
                }
            }
        }
    }
    return dist[dst]==INT_MAX ? -1 : dist[dst];
}
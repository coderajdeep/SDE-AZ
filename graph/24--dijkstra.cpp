
// https://youtu.be/3dINsjyfooY?list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn
// Using Queue
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int, int>> adj[vertices];
    for(vector<int> e : edge) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(pair<int, int> p : adj[u]) {
            int v = p.first;
            int dis = p.second;
            if(dist[u]+dis<dist[v]) {
                dist[v] = dis + dist[u];
                q.push(v);
            }
        }
    }
    return dist;
}


// Using Priority Queue
// Time complexity O(E * log V)
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int, int>> adj[vertices];
    for(vector<int> e : edge) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        int u = p.second;
        pq.pop();
        for(pair<int, int> pr : adj[u]) {
            int v = pr.first;
            int dis = pr.second;
            if(dist[u]+dis<dist[v]) {
                dist[v] = dis + dist[u];
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Using set
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    vector<pair<int, int>> adj[vertices];
    for(vector<int> e : edge) {
        int u = e[0];
        int v = e[1];
        int w = e[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> st;
    st.insert({0, source});
    while(!st.empty()) {
        pair<int, int> p = *st.begin();
        int u = p.second;
        st.erase(st.begin());
        for(pair<int, int> pr : adj[u]) {
            int v = pr.first;
            int dis = pr.second;
            if(dist[u]+dis<dist[v]) {
                if(dist[v] != INT_MAX) {
                    st.erase({dist[v], v});
                }
                dist[v] = dis + dist[u];
                st.insert({dist[v], v});
            }
        }
    }
    return dist;
}
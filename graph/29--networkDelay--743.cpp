// Network delay time -- leetcode 743
// Time complexity O(E * log(n))
// E : times.size()
// Space complexity O(E + n) + O(n)
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> adj[n+1];
    for(vector<int> time : times) {
        adj[time[0]].push_back({time[1], time[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> time(n+1, INT_MAX);
    time[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        pair<int, int> node = pq.top();
        pq.pop();
        int u = node.second;
        for(pair<int, int> p : adj[u]) {
            int time_v = p.second;
            int v = p.first;
            if(time[u]+time_v < time[v]) {
                time[v] = time[u]+time_v;
                pq.push({time[v], v});
            }
        }
    }
    int minTime = INT_MIN;
    for(int i=1; i<=n; ++i) {
        minTime = max(minTime, time[i]);
    }
    return minTime==INT_MAX ? -1 : minTime;
}
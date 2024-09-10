// Number of ways to reach a destination -- leetcode 1976
// Time complexity O(E * log(n))
// E : roads.size()
// Space complexity O(E + N) + O(N)
// [[0,1,1],[1,2,4],[0,4,3],[3,2,5],[3,4,1],[3,0,5],[1,3,1]]
// Very good test case
int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for(vector<int> road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }
    vector<long> times(n, LONG_MAX), ways(n, 0);
    times[0] = 0;
    ways[0] = 1;
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
    pq.push({0, 0});
    long mod = 1e9+7;
    while(!pq.empty()) {
        pair<long, long> node = pq.top();
        pq.pop();
        long u = node.second;
        long time = node.first;
        for(pair<int, int> p : adj[u]) {
            long v = p.first;
            long cost = p.second;
            long total = time + cost;
            if(total < times[v]) {
                times[v] = total;
                ways[v] = ways[u];
                pq.push({times[v], v});
            }
            // as we are checking total == times[v]
            // We need to always find total as (time + cost) not (times[u] + cost)
            // Because times[u] will be updated
            // In the above test case this was happening
            // In normal Dijkstra, we can do that because we don't consider the equal case
            else if(total == times[v]) {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }
    return ways[n-1];
}
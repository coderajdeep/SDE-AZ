// Minimum multiplication operations to reach from start to end -- Coding Ninjas
// Time complexity O(mod * n)
// Space complexity O(mod * n)
// Both complexity depends on the array
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    int mod = 1e3;
    vector<int> step(mod, INT_MAX);
    queue<pair<int, int>> q;
    q.push({start, 0});
    step[start] = 0;
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int u = node.first;
        int stp = node.second;
        // start can be equal to end
        if(u==end) return stp;
        for(int val : a) {
            int v = (val*u) % mod;
            if(stp+1 < step[v]) {
                q.push({v, stp+1});
                step[v] = stp+1;
            }
        }
    }
    return -1;
}
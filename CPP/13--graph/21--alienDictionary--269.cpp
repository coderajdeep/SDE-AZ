// Alien Dictionary -- leetcode 269
// Time complexity O(n*size) + O(K+E)
// Space complexity O(K) + O(K+E)
string getAlienLanguage(vector<string> &dictionary, int k) {
    vector<int> adj[k];
    int n = dictionary.size();
    vector<int> indegree(k, 0);
    for(int i=1; i<n; ++i) {
        int n1 = dictionary[i-1].size();
        int n2 = dictionary[i].size();
        for(int j=0; j<n1 && j<n2; ++j) {
            if(dictionary[i-1][j] != dictionary[i][j]) {
                int u = dictionary[i-1][j] - 'a';
                int v = dictionary[i][j] - 'a';
                adj[u].push_back(v);
                indegree[v]++;
                break;
            }
        }
    }
    queue<int> q;
    for(int i=0; i<k; ++i) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    string ans;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back('a'+u);
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
            }
        }
    }
    return ans;
}
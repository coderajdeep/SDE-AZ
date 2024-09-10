// Using DFS
// Time complexity O(V+E)
// Space complexity O(V)
bool dfs(int u, vector<bool> &visited, vector<bool> &path, vector<int> *adj) {
	visited[u] = true;
	path[u] = true;
	for(int v : adj[u]) {
		if(!visited[v]) {
			if(dfs(v, visited, path, adj)) return true;
		}
		else if(path[v]) return true;
	}
	// we are not changing visited[u] because if we do dfs(u) later, this will give false only
	// so we are optimizing this
	path[u] = false;
	return false;
}
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
	for(int i=0; i<e; ++i) {
		adj[edges[i][0]].push_back(edges[i][1]);
	}
	vector<bool> visited(v, false), path(v, false);
	for(int i=0; i<v; ++i) {
		if(!visited[i] && dfs(i, visited, path, adj)) return true;
	}
	return false;
}

// Using BFS
// Time complexity O(V+E)
// Space complexity O(V)
bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	vector<int> adj[v];
    vector<int> indegree(v, 0);
    for(int i=0; i<e; ++i) {
        adj[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    vector<int> ans(v);
    int index = 0;
    queue<int> q;
    for(int i=0; i<v; ++i) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        ans[index++] = u;
        q.pop();
        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
            }
        }
    }
    return (v!=index);
}


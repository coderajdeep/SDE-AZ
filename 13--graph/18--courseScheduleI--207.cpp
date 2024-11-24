// Course schedule I -- leetcode 207

// Using DFS
// Time complexity O(V + E) where V = numCourses and E = prerequisites.size()
// Space complexity O(V + E) + O(2 * V)
bool dfs(int u, vector<bool> &visited, vector<bool> &path, vector<int> *adj) {
    visited[u] = true;
    path[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(dfs(v, visited, path, adj)) return true;
        }
        else if(path[v]) return true;
    }
    path[u] = false;
    return false;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<bool> visited(numCourses, false), path(numCourses, false);
    vector<int> adj[numCourses];
    for(vector<int> arr : prerequisites) {
        adj[arr.back()].push_back(arr.front());
    }
    for(int i=0; i<numCourses; ++i) {
        // if this is true then there is a cycle
        // if there is a cycle then topo sort is not possible
        if(!visited[i] && dfs(i, visited, path, adj)) return false;
    }
    return true;
}

// Using BFS
// Time complexity O(V + E) where V = numCourses and E = prerequisites.size()
// Space complexity O(V + E) + O(V)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses, 0);
    for(vector<int> arr : prerequisites) {
        adj[arr.back()].push_back(arr.front());
        indegree[arr.front()]++;
    }
    queue<int> q;
    for(int i=0; i<numCourses; ++i) {
        if(indegree[i]==0) q.push(i);
    }
    vector<int> ans(numCourses);
    int index = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans[index++] = node;
        for(int v : adj[node]) {
            indegree[v]--;
            if(indegree[v]==0) {
                q.push(v);
            }
        }
    }
    return (index==numCourses);
}
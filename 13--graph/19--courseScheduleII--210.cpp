// Course schedule II -- leetcode 210

// Using DFS
// Time complexity O(V + E) where V = numCourses and E = prerequisites.size()
// Space complexity O(V + E) + O(2 * V)
bool dfs(int u, vector<bool> &visited, vector<bool> &path, stack<int> &stk, vector<int> *adj) {
    visited[u] = true;
    path[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            if(dfs(v, visited, path, stk, adj)) return true;
        }
        else if(path[v]) return true;
    }
    stk.push(u);
    path[u] = false;
    return false;
}
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    for(vector<int> arr : prerequisites) {
        adj[arr.back()].push_back(arr.front());
    }
    vector<bool> visited(numCourses, false), path(numCourses, false);
    stack<int> stk;
    for(int i=0; i<numCourses; ++i) {
        if(!visited[i] && dfs(i, visited, path, stk, adj)) return vector<int> {};
    }
    vector<int> ans(numCourses);
    int index = 0;
    while(!stk.empty()) {
        ans[index++] = stk.top();
        stk.pop();
    }
    return ans;
}


// Using BFS
// Time complexity O(V + E) where V = numCourses and E = prerequisites.size()
// Space complexity O(V + E) + O(2 * V)
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
    return (index==numCourses) ? ans : vector<int> {};
}
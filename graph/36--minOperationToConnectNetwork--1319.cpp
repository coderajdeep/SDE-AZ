// Solution1
// Best solution
int getParent(int node, vector<int> &parent) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node], parent);
}
void unionBySize(int par1, int par2, vector<int> &parent, vector<int> &sizes) {
    if(sizes[par1] < sizes[par2]) {
        parent[par1] = par2;
        sizes[par2] += sizes[par1];
    }
    else {
        parent[par2] = par1;
        sizes[par1] += sizes[par2];
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    int size = connections.size();
    if(size<(n-1)) return -1;
    vector<int> parent(n), sizes(n);
    for(int i=0; i<n; ++i) {
        parent[i] = i;
        sizes[i] = 1;
    }
    for(vector<int> connection : connections) {
        int u = connection[0];
        int v = connection[1];
        int par1 = getParent(u, parent);
        int par2 = getParent(v, parent);
        if(par1 != par2) {
            unionBySize(par1, par2, parent, sizes);
        }
    }
    int ultParent = 0;
    for(int i=0; i<n; ++i) {
        if(parent[i]==i) {
            ++ultParent;
        }
    }
    return (ultParent-1);
}


// Solution 2
// Same solution (striver way)
int getParent(int node, vector<int> &parent) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node], parent);
}
void unionBySize(int par1, int par2, vector<int> &parent, vector<int> &sizes) {
    if(sizes[par1] < sizes[par2]) {
        parent[par1] = par2;
        sizes[par2] += sizes[par1];
    }
    else {
        parent[par2] = par1;
        sizes[par1] += sizes[par2];
    }
}
int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> parent(n), sizes(n);
    for(int i=0; i<n; ++i) {
        parent[i] = i;
        sizes[i] = 1;
    }
    int edgeAvailable = 0;
    for(vector<int> connection : connections) {
        int u = connection[0];
        int v = connection[1];
        int par1 = getParent(u, parent);
        int par2 = getParent(v, parent);
        if(par1 != par2) {
            unionBySize(par1, par2, parent, sizes);
        }
        else ++edgeAvailable;
    }
    int totalComponent = 0;
    for(int i=0; i<n; ++i) {
        if(parent[i]==i) {
            ++totalComponent;
        }
    }

    if(totalComponent-1 > edgeAvailable) return -1;
    return (totalComponent-1);
}

// solution 3
void dfs(int u, vector<int> *adj, vector<bool> &visited) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
int getTotalComponent(int n, vector<vector<int>>& connections) {
    vector<int> adj[n];
    for(vector<int> connection : connections) {
        int u = connection[0];
        int v = connection[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; ++i) {
        if(!visited[i]) {
            ++cnt;
            dfs(i, adj, visited);
        }
    }
    return cnt;
}
int makeConnected(int n, vector<vector<int>>& connections) {
    int size = connections.size();
    if(size<(n-1)) return -1;
    int totalComponent = getTotalComponent(n, connections);
    return totalComponent-1;
}
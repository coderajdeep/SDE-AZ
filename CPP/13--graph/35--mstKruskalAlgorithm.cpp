static bool comp(vector<int> &a, vector<int> &b) {
	return a.back() < b.back();
}

int getParent(int node, vector<int> &parent) {
	if(parent[node] == node) return node;
	return parent[node] = getParent(parent[node], parent);
}

void unionBySize(int par1, int par2, vector<int> &sizes, vector<int> &parent) {
	if(sizes[par1] < sizes[par2]) {
		parent[par1] = par2;
		sizes[par2] += sizes[par1];
	}
	else {
		parent[par2] = par1;
		sizes[par1] += sizes[par2];
	}
}

void unionByRank(int par1, int par2, vector<int> &ranks, vector<int> &parent) {
	if(ranks[par1] < ranks[par2]) {
		parent[par1] = par2;
	}
	else if(ranks[par1] > ranks[par2]) {
		parent[par2] = par1;
	}
	else {
		parent[par2] = par1;
		ranks[par1]++;
	}
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
	sort(edges.begin(), edges.end(), comp);
	vector<int> parent(n), sizes(n), ranks(n);
	for(int i=0; i<n; ++i) {
		parent[i] = i;
		sizes[i] = 1;
		ranks[i] = 0;
	}
	int sum = 0;
	for(vector<int> &edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int w = edge[2];
		int par1 = getParent(u, parent);
		int par2 = getParent(v, parent);
		if(par1 != par2) {
			sum += w;
			unionByRank(par1, par2, ranks, parent);
		}
	}
	return sum;
}
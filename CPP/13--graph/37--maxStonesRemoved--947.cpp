// Number of operations to make network connected -- leetcode 1319
int getParent(int node, vector<int> &parent) {
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node], parent);
}
void unionBySize(int node1, int node2, vector<int> &parent, vector<int> &sizes) {
    int par1 = getParent(node1, parent);
    int par2 = getParent(node2, parent);
    if(par1 != par2) {
        if(sizes[par1] < sizes[par2]) {
            parent[par1] = par2;
            sizes[par2] += sizes[par1];
        }
        else {
            parent[par2] = par1;
            sizes[par1] += sizes[par2];
        }
    }
}
int removeStones(vector<vector<int>>& stones) {
    int maxRow = -1;
    int maxCol = -1;
    for(vector<int> &stone : stones) {
        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }
    int size = maxRow + maxCol + 2;
    vector<int> parent(size), sizes(size, 1);
    for(int i=0; i<size; ++i) {
        parent[i] = i;
    }
    for(vector<int> &stone : stones) {
        int row = stone[0];
        int col = maxRow + stone[1] + 1;
        unionBySize(row, col, parent, sizes);
    }
    int cnt = 0;
    for(int i=0; i<size; ++i) {
        if(sizes[i]>1 && parent[i]==i) ++cnt;
    }
    return stones.size() - cnt;
}
void dfs(int r, int c, int row, int col, string &path, char ch, int** arr, vector<vector<bool>> &visited) {
    if(r<0 || r>=row || c<0 || c>=col || arr[r][c]==0 || visited[r][c]) return;
    visited[r][c] = true;
    path.push_back(ch);
    dfs(r-1, c, row, col, path, 'u', arr, visited);
    dfs(r, c+1, row, col, path, 'r', arr, visited);
    dfs(r+1, c, row, col, path, 'd', arr, visited);
    dfs(r, c-1, row, col, path, 'l', arr, visited);
    path.push_back('e');
}
int distinctIslands(int** arr, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_set<string> uset;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            string path;
            if(arr[i][j]==1 && visited[i][j]==false) {
                dfs(i, j, n, m, path, 's', arr, visited);
                uset.insert(path);
            }
        }
    }
    return uset.size();
}
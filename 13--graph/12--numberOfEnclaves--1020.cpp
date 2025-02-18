// *** Number of enclaves -- leetcode 1020
// Time complexity O(n*m)
// Space complexity O(n*m)
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; ++i) {
            if(grid[i][0]==1) {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if(grid[i][m-1]==1) {
                q.push({i, m-1});
                visited[i][m-1] = true;
            }
        }
        for(int i=0; i<m; ++i) {
            if(grid[0][i]==1) {
                q.push({0, i});
                visited[0][i] = true;
            }
            if(grid[n-1][i]==1) {
                q.push({n-1, i});
                visited[n-1][i] = true;
            }
        }
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for(int i=0; i<4; ++i) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1 && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        int count = 0;
        for(int i=1; i<n-1; ++i) {
            for(int j=1; j<m-1; ++j) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};

// DFS solution
// Time complexity O(n*m)
// Space complexity O(n*m)
class Solution {
private:
    void dfs(int x, int y, int n, int m, vector<vector<int>>& grid) {
        if(x<0 || x>=n || y<0 || y>=m || (grid[x][y] == 0)) return;
        grid[x][y] = 0;
        dfs(x+1, y, n, m, grid);
        dfs(x-1, y, n, m, grid);
        dfs(x, y+1, n, m, grid);
        dfs(x, y-1, n, m, grid);
    }    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; ++i) {
            if(grid[i][0]) {
                dfs(i, 0, n, m, grid);
            }
            if(grid[i][m-1]) {
                dfs(i, m-1, n, m, grid);
            }
        }
        for(int i=0; i<m; ++i) {
            if(grid[0][i]) {
                dfs(0, i, n, m, grid);
            }
            if(grid[n-1][i]) {
                dfs(n-1, i, n, m, grid);
            }
        }
        int count = 0;
        for(int i=1; i<n-1; ++i) {
            for(int j=1; j<m-1; ++j) {
                if(grid[i][j]) {
                    ++count;
                }
            }
        }
        return count;
    }
};
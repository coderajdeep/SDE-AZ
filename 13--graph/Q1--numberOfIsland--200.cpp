// Number of Islands -- leetcode 200
// Solved using dfs
// TODO : need to solve this uisng BFS
// Time complexity O(n*m)
// Space complexity O(n*m)
class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1' || visited[i][j]) return;
        visited[i][j] = true;
        dfs(i+1, j, n, m, grid, visited);
        dfs(i-1, j, n, m, grid, visited);
        dfs(i, j+1, n, m, grid, visited);
        dfs(i, j-1, n, m, grid, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    ++count;
                    dfs(i, j, n, m, grid, visited);
                }
            }
        }
        return count;
    }
};


// Number of Islands -- https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1
// Solved using dfs
// Time complexity O(n*m)
// Space complexity O(n*m)
// 8 directional movement
class Solution {
    private:
        void dfs(int x, int y, int n, int m, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
            if(x<0 || x>=n || y<0 || y>=m || grid[x][y] == '0' || visited[x][y]) return;
            visited[x][y] = true;
            for(int i=-1; i<=1; ++i) {
                for(int j=-1; j<=1; ++j) {
                    dfs(x+i, y+j, n, m, visited, grid);
                }
            }
        }
    public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j]=='1' && !visited[i][j]) {
                    ++count;
                    dfs(i, j, n, m, visited, grid);
                }
            }
        }
        return count;
    }
};
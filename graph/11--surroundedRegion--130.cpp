class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for(int i=0; i<n; ++i) {
            if(board[i][0]=='O') {
                q.push({i, 0});
                visited[i][0] = true;
            }
            if(board[i][m-1]=='O') {
                q.push({i, m-1});
                visited[i][m-1] = true;
            }
        }
        for(int i=0; i<m; ++i) {
            if(board[0][i]=='O') {
                q.push({0, i});
                visited[0][i] = true;
            }
            if(board[n-1][i]=='O') {
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
                if(x>=0 && x<n && y>=0 && y<m && !visited[x][y] && board[x][y]=='O') {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        for(int i=1; i<n-1; ++i) {
            for(int j=1; j<m-1; ++j) {
                if(board[i][j]=='O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
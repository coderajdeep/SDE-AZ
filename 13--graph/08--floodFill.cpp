// Time complexity O(n*m)
// Space complexity O(n*m)

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int row = image.size();
    int col = image[0].size();
    int startColor = image[sr][sc];
    if(startColor == color) return image;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x>=0 && x<row && y>=0 && y<col && image[x][y]==startColor) {
                image[x][y] = color;
                q.push({x, y});
            }
        }
    }

    return image;
}

// Time complexity O(n*m)
// Space complexity O(n*m)

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int row = image.size();
    int col = image[0].size();
    int startColor = image[sr][sc];
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    visited[sr][sc] = true;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for(int i=0; i<4; ++i) {
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x>=0 && x<row && y>=0 && y<col && image[x][y]==startColor && !visited[x][y]) {
                image[x][y] = color;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }

    return image;
}
// Rotting Oranges -- leetcode 994
// Best solution
// Time complexity O(n*m)
// Space complexity O(n*m)
class Solution {
private:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    bool isValid(int x, int y, int n, int m) {
        return (x>=0 && x<n && y>=0 && y<m);
    }    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int freshCount = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }
        int time = 0;
        int fresh2rotten = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; ++i) {
                pair<int, int> node = q.front();
                q.pop();
                for(int i=0; i<4; ++i) {
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];
                    if(isValid(x, y, n, m) && grid[x][y]==1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        ++fresh2rotten;
                    }
                }
            }
            if(q.empty()) {
                if(fresh2rotten != freshCount) return -1;
                return time;
            }
            ++time;
        }
        // if freshCount>0 then needs to return -1
        // if all of the elements are zero i.e. empty then needs to return zero
        return freshCount != 0 ? -1 : 0;
    }
};


// Time complexity O(n*m)
// Space complexity O(n*m)
struct Node {
    int x, y, time;
    Node(int x, int y, int time) {
        Node::x = x;
        Node::y = y;
        Node::time = time;
    }
};

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

bool isValid(int x, int y, int n, int m) {
    return (x>=0 && x<n && y>=0 && y<m);
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<Node> q;
        int freshCount = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
                else if(grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }
        int maxTime = 0;
        int fresh2rotten = 0;
        while(!q.empty()) {
            Node node = q.front();
            maxTime = max(maxTime, node.time);
            int time = node.time + 1;
            q.pop();
            for(int i=0; i<4; ++i) {
                int x = node.x + dx[i];
                int y = node.y + dy[i];
                if(isValid(x, y, n, m) && grid[x][y]==1) {
                    grid[x][y] = 2;
                    q.push({x, y, time});
                    ++fresh2rotten;
                }
            }
        }
        if(fresh2rotten != freshCount) return -1;
        return maxTime;
    }
};
// 0 1 Matrix -- leetcode 542
// Time complexity O(n*m)
// Space complexity O(n*m)
struct Node{
    int x, y, dis;
    Node(int x, int y, int dis) {
        Node::x = x;
        Node::y = y;
        Node::dis = dis;
    }
};
class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<Node> q;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(mat[i][j]==0) {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            Node node = q.front();
            q.pop();
            int dis = node.dis + 1;
            for(int i=0; i<4; ++i) {
                int x = node.x + dx[i];
                int y = node.y + dy[i];
                if(x>=0 && x<n && y>=0 && y<m && mat[x][y]==1 && dist[x][y]==-1) {
                    dist[x][y] = dis;
                    q.push({x, y, dis});
                }
            }
        }
        return dist;
    }
};
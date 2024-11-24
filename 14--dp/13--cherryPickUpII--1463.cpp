// Cherry Pickup II -- leetcode 1463

// Space optimized tabulation
// Time complexity O(n*m*m)
// Space complexity O(m*m)
bool isValid(int col1, int col2, int cols) {
    return (col1>=0 && col1<cols && col2>=0 && col2<cols);
}
int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> prev(cols, vector<int>(cols)), curr(cols, vector<int>(cols));
    for(int index=rows-1; index>=0; --index) {
        for(int col1=0; col1<cols; ++col1) {
            for(int col2=0; col2<cols; ++col2) {
                int maxValue = INT_MIN;
                for(int i=-1; i<=1; ++i) {
                    for(int j=-1; j<=1; ++j) {
                        int c1 = col1 + i;
                        int c2 = col2 + j;
                        if(isValid(c1, c2, cols)) {
                            int value = (index == rows-1) ? 0 : prev[c1][c2];
                            if(col1 == col2) {
                                value = grid[index][col1] + value;
                            }
                            else {
                                value = grid[index][col1] + grid[index][col2] + value;
                            }
                            maxValue = max(maxValue, value);
                        }
                    }
                }
                curr[col1][col2] = maxValue;
            }
        }
        for(int col1=0; col1<cols; ++col1) {
            for(int col2=0; col2<cols; ++col2) {
                prev[col1][col2] = curr[col1][col2];
            }
        }
    }
    return prev[0][cols-1];
}

// Tabulation
// Time complexity O(n*m*m)
// Space complexity O(n*m*m)
bool isValid(int col1, int col2, int cols) {
    return (col1>=0 && col1<cols && col2>=0 && col2<cols);
}
int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
    for(int index=rows-1; index>=0; --index) {
        for(int col1=0; col1<cols; ++col1) {
            for(int col2=0; col2<cols; ++col2) {
                int maxValue = INT_MIN;
                for(int i=-1; i<=1; ++i) {
                    for(int j=-1; j<=1; ++j) {
                        int c1 = col1 + i;
                        int c2 = col2 + j;
                        if(isValid(c1, c2, cols)) {
                            int value = (index == rows-1) ? 0 : dp[index+1][c1][c2];
                            if(col1 == col2) {
                                value = grid[index][col1] + value;
                            }
                            else {
                                value = grid[index][col1] + grid[index][col2] + value;
                            }
                            maxValue = max(maxValue, value);
                        }
                    }
                }
                dp[index][col1][col2] = maxValue;
            }
        }
    }
    return dp[0][0][cols-1];
}

// Time complexity O(row*col*col)
// Space complexity O(row*col*col)

bool isValid(int col1, int col2, int cols) {
    return (col1>=0 && col1<cols && col2>=0 && col2<cols);
}

int solve(int index, int col1, int col2, int rows, int cols, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
    if(index==rows-1) {
        if(col1 == col2) {
            return grid[index][col1];
        }
        else {
            return grid[index][col1] + grid[index][col2];
        }
    }

    if(dp[index][col1][col2] != -1) return dp[index][col1][col2];

    int maxValue = INT_MIN;
    for(int i=-1; i<=1; ++i) {
        for(int j=-1; j<=1; ++j) {
            int c1 = col1 + i;
            int c2 = col2 + j;
            if(isValid(c1, c2, cols)) {
                int value = solve(index+1, c1, c2, rows, cols, grid, dp);
                if(col1 == col2) {
                    value = grid[index][col1] + value;
                }
                else {
                    value = grid[index][col1] + grid[index][col2] + value;
                }
                maxValue = max(maxValue, value);
            }
        }
    }
    return dp[index][col1][col2] = maxValue;
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return solve(0, 0, m-1, n, m, grid, dp);
}
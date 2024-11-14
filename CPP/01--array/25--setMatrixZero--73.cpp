// Set Matrix Zero -- leetcode 73

// Solution 1
// Best approach
// Time Complexity O(2*n*m)
// Space Complexity O(1)
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size(), firstColumn = -1;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j]==0) {
                // This is for row tracking
                matrix[i][0] = 0;

                // This is for column tracking
                if(j==0) {
                    firstColumn = 0;
                }
                else {
                    matrix[0][j] = 0;
                }

            }
        }
    }
    // Good explanation
    // https://youtu.be/N0MgLvceX7M?t=1270
    // We need to traverse from bottom to up and right to left
    // if we traverse from top to bottom then we can modify first row
    // and if we traverse from left to right then we can modify first column
    // so we need to avoid this and traverse bottom to up and right to left
    for(int i=n-1; i>=0; --i) {
        for(int j=m-1; j>=0; --j) {
            if(j==0) {
                if(firstColumn==0) {
                    matrix[i][j] = 0;
                }
            }
            else if(matrix[0][j]==0 || matrix[i][0]==0) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Solution 2
// Using some extra space
// Time O(2*n*m) ~ O(n*m)
// Space O(n+m)
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    bool row[n], col[m];
    for(int i=0; i<n; ++i) row[i] = false;
    for(int i=0; i<m; ++i) col[i] = false;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j]==0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}

// Solution 3
// Brute fource
// time O(n^3) ~ )(n*n*(n+m))
// space O(1)
// this process is not always correct
// depens on matrix data range
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j]==0) {
                for(int r=0; r<n; ++r) {
                    if(matrix[r][j] != 0) {
                        matrix[r][j] = 1e9;
                    }
                }
                for(int c=0; c<m; ++c) {
                    if(matrix[i][c] != 0) {
                        matrix[i][c] = 1e9;
                    }
                }
                }
        }
    }
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j] == 1e9) {
                matrix[i][j] = 0;
            }
        }
    }
}
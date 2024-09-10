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
    // We are traversing from right to left
    // Because if we traverse from left to write then we can overwrite matrix[0][j] and matrix[i][0]
    // when matrix[0][0] is zero and firstColumn = 0 respectively
    // if we want to traverse left to write then we need to avoid first row and column while 
    // filling the matrix with zero and later we can fill first row and column
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
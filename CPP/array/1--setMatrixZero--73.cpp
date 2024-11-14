// leetcode 73
// set matrix zero

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


// Time O(2*n^2) ~ O(n^2)
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
            if(row[i]==1 || col[j]==1) {
                matrix[i][j] = 0;
            }
        }
    }
}



// Time O(2*n^2) ~ O(n^2)
// Space O(1)
void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col = 0; // this is for tracking first column
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j]==0) {
                matrix[i][0] = 0;
                if(j==0) col = 1;
                else matrix[0][j] = 0;
            }
        }
    }
    // edge case
    // [[-4,-2147483648,6,-7,0],[-8,6,-8,-6,0],[2147483647,2,-9,-6,-10]]
    for(int i=n-1; i>=0; --i) {
        for(int j=m-1; j>=0; --j) {
            if(matrix[i][0]==0 || (j!=0 && matrix[0][j]==0)) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if(col) for(int i=0; i<n; ++i) matrix[i][0] = 0;
}
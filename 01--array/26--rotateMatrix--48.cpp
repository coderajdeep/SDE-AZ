// Rotate a matrix by clockwise 90 degree -- leetcode 48

// Time complexity O(2*n*n)
// Space complexity O(1)
// We can do this in place if the matrix is a square matrix
// if the matrix is a rectangular matrix, then in place rotation is tough
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // transpose matrix
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; ++i) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}


// Time complexity O(2*n*n)
// Space complexity O(n*n)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> copyMatrix(matrix.begin(), matrix.end());
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            matrix[j][n-1-i] = copyMatrix[i][j];
        }
    }
}
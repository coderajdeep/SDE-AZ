// leetcode 48
// Rotate a matrix by clockwise 90 degree


// Time complexity O(n^2)
// Space complexity O(n^2)
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> temp(matrix.begin(), matrix.end());
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            matrix[j][n-1-i] = temp[i][j];
        }
    }
}

// Time complexity O(n^2)
// Space complexity O(1)
// Best approach
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int start, int end, vector<int>& arr) {
    while(start<end) {
        swap(arr[start++], arr[end--]);
    }
}
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Transport the matrix
    for(int i=1; i<n; ++i) {
        for(int j=0; j<=i; ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row
    for(int i=0; i<n; ++i) {
        reverseArray(0, n-1, matrix[i]);
    }
}
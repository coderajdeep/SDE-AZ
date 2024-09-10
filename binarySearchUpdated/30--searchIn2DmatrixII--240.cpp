// Solution 1
// Best approach
// Time complexity O(n+m)
// Space complexity O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int row = 0, col = m-1;
    while(row<n && col>=0) {
        if(matrix[row][col]==target) return true;
        if(matrix[row][col]>target) --col;
        else ++row;
    }
    return false;
}

// Solution 2
// Time complexity O(nlogm)
// Space complexity O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    for(int i=0; i<n; ++i) {
        if(binary_search(matrix[i].begin(), matrix[i].end(), target)) {
            return true;
        }
    }
    return false;
}
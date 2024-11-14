// Time complexity O(nlogm)
// Space complexity O(1)
int getMaxRowIndex(vector<vector<int>> &mat, int col, int n) {
    int val = INT_MIN, row;
    for(int i=0; i<n; ++i) {
        if(mat[i][col]>val) {
            val = mat[i][col];
            row = i; 
        }
    }
    return row;
}
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        int rowIdx = getMaxRowIndex(mat, mid, n);
        int midValue = mat[rowIdx][mid];
        int leftValue = mid>0 ? mat[rowIdx][mid-1] : -1;
        int rightValue = mid<m-1 ? mat[rowIdx][mid+1] : -1;
        int topValue = rowIdx>0 ? mat[rowIdx-1][mid] : -1;
        int bottomValue = rowIdx<n-1 ? mat[rowIdx+1][mid] : -1;
        if(midValue>leftValue && midValue>rightValue && midValue>topValue && midValue>bottomValue) {
            return vector<int> {rowIdx, mid};
        }
        if(midValue < mat[rowIdx][mid+1]) low = mid+1;
        else high = mid-1;
    }
    return vector<int> {-1, -1};
}
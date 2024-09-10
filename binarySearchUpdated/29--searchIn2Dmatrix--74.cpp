// Time complexity O(logn + logm)
// Space complexity O(1)
int searchInCol(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int low = 0, high = n-1, mid;
    while(low<high) {
        mid = low + (high-low)/2;
        if(target <= matrix[mid][0]) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    if(target<matrix[0][0]) return false;
    if(target>matrix[n-1][m-1]) return false;
    if(target>matrix[n-1][0]) {
        return binary_search(matrix[n-1].begin(), matrix[n-1].end(), target);
    }
    int index = searchInCol(matrix, target);
    if(target == matrix[index][0]) return true;
    return binary_search(matrix[index-1].begin(), matrix[index-1].end(), target);
}
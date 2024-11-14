// leetcode 74/240
// Search in 2D sorted matrix

// Time complexity O(n*m)
// Space complexity O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(matrix[i][j]==target) {
                return true;
            }
        }
    }
    return false;
}

// Time complexity O(N + logM)
// Space complexity O(1)
bool binarySearch(int low, int high, vector<int> &arr, int target) {
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid]==target) {
            return true;
        }
        if(arr[mid]<target) {
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0; i<n; ++i) {
        if(matrix[i][0]<=target && matrix[i][m-1]>=target) {
            return binarySearch(0, m-1, matrix[i], target);
        }
    }
    return false;
}

// Time complexity O(n*m)
// Space complexity O(1)
// Best approach
pair<int, int> convertPosition(int num, int col) {
        return {num/col, num%col};
    }
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = (n*m)-1, mid, x, y;
    pair<int, int> pos;
    while(low<=high) {
        mid = low + (high-low)/2;
        pos = convertPosition(mid, m);
        x = pos.first;
        y = pos.second;
        if(matrix[x][y]==target) {
            return true;
        }
        if(matrix[x][y]<target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return false;
}
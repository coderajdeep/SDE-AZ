// Print matrix in spiral order  -- leetcode 54

// Time complexity O(n*m)
// Space complexity O(n*m) [This space is used for storing the answer]
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<int> ans(n*m);
    int left = 0, right = m-1, top = 0, bottom = n-1, index = 0;
    
    while(left<=right && top<=bottom) {
        for(int i=left; i<=right; ++i) {
            ans[index++] = matrix[top][i];
        }
        ++top;
        for(int i=top; i<=bottom; ++i) {
            ans[index++] = matrix[i][right];
        }
        --right;
        // here we are check top & bottom condition because left & right will be checked inner loop
        // if we don't check, then this will give segmentation fault
        if(top<=bottom) {
            for(int i=right; i>=left; --i) {
                ans[index++] = matrix[bottom][i];
            }
            --bottom;
        }
        // similarly
        // here we are check left & right condition because top & bottom will be checked inner loop
        // if we don't check, then this will give segmentation fault
        if(left<=right) {
            for(int i=bottom; i>=top; --i) {
                ans[index++] = matrix[i][left];
            }
            ++left;
        }
    }
    return ans;
}
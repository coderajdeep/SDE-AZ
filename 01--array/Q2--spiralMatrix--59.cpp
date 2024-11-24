// Spiral Matrix II -- leetcode 59
// Time complexity O(n*m)
// Space complexity O(n*m) [This space is used for storing the answer]

vector<vector<int>> generateMatrix(int n) {
    int left = 0, right = n-1, top = 0, bottom = n-1, value = 1;
    vector<vector<int>> ans(n, vector<int>(n));
    while(left<=right && top<=bottom) {
        for(int i=left; i<=right; ++i) {
            ans[top][i] = value++;
        }
        top++;
        for(int i=top; i<=bottom; ++i) {
            ans[i][right] = value++;
        }
        right--;
        if(top<=bottom) {
            for(int i=right; i>=left; --i) {
                ans[bottom][i] = value++;
            }
            bottom--;
        }
        if(left<=right) {
            for(int i=bottom; i>=top; --i) {
                ans[i][left] = value++;
            }
            left++;
        }
    }
    return ans;
}
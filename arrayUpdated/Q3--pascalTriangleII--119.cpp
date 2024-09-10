// Pascal Triangle II

// Time complexity O(n^2)
// Space complexity O(n)

vector<int> getRow(int rowIndex) {
    vector<int>ans(rowIndex+1, 1);
    if(rowIndex<=1) return ans;
    int prev, curr;
    for(int row=2; row<=rowIndex; ++row) {
        prev = 1;
        for(int index=1; index<row; ++index) {
            curr = ans[index];
            ans[index] = prev + curr;
            prev = curr;
        }
    }
    return ans;
}
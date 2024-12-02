// Pascal Triangle II

// Best solution
// Mathimatical
// Time complexity O(n)
// Space complexity O(n) [space is used to store the result]
vector<int> getRow(int rowIndex) {
    if(rowIndex==0) return {1};
    if(rowIndex==1) return {1, 1};
    vector<int> ans(rowIndex+1);
    ans[0] = ans[rowIndex] = 1;
    for(int i=1; i<=rowIndex; ++i) {
        long mul = ((long)ans[i-1] * (long)(rowIndex+1-i));
        ans[i] =  mul / i;
    }
    return ans;
}

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
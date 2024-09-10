// leetcode 118
// Pascal's triangle

// time complexity O(n^2)
// space complexity O(n^2)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for(int i=0; i<numRows; ++i) {
        vector<int>temp(i+1, 1);
        for(int index=1; index<i; ++index) {
            temp[index] = ans[i-1][index-1] + ans[i-1][index];
        }
        ans[i] = temp;
    }
    return ans;
}
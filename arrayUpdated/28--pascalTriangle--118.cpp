// Pascal Triangle

// Time complexity O(n^2)
// Space complexity O(n^2)
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    ans[0].push_back(1);
    if(numRows==1) return ans;
    ans[1] = vector<int>{1, 1};
    if(numRows==2) return ans;

    for(int numRow=2; numRow<numRows; ++numRow) {
        ans[numRow].resize(numRow+1);
        ans[numRow][0] = ans[numRow][numRow] = 1;
        for(int index=1; index<numRow; ++index) {
            ans[numRow][index] = (ans[numRow-1][index-1] + ans[numRow-1][index]);
        }
    }

    return ans;
}

// Same solution
// Just array insertion is different
vector<vector<int>> generate(int numRows) {
    if(!numRows) return {};
    vector<vector<int>> ans(numRows);
    ans[0] = {1};
    if(numRows==1) return ans;
    ans[1] = {1, 1};
    if(numRows==2) return ans;
    for(int i=2; i<numRows; ++i) {
        vector<int> temp(i+1);
        temp[0] = temp[i] = 1;
        for(int j=1; j<i; ++j) {
            temp[j] = ans[i-1][j-1] + ans[i-1][j];
        }
        ans[i] = temp;
    }
    return ans;
}
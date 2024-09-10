// Time complexity O(n*log2(m)*log2(largest-smallest) + 2*n)
// Space complexity O(1)
int getCount(vector<vector<int>> &matrix, int R, int C, int target) {
    int count = 0;
    for(int i=0; i<R; ++i) {
        if(matrix[i][C-1]<=target) {
            count += C;
        }
        else if(matrix[i][0]>target) {
            count += 0;
        }
        else {
            int idx = upper_bound(matrix[i].begin(), matrix[i].end(), target) - matrix[i].begin();
            count += idx;
        }
    }
    return count;
}
int median(vector<vector<int>> &matrix, int R, int C){
    int low = INT_MAX, high = INT_MIN, mid, ans = -1, targetCount = ((R*C)/2);
    for(int i=0; i<R; ++i) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C-1]);
    }
    while(low<=high) {
        mid = low + (high-low)/2;
        int count = getCount(matrix, R, C, mid);
        if(targetCount<count) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}
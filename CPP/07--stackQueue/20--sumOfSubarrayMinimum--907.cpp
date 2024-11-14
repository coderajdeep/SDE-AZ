// Sum of subarray minimum -- leetcode 907
// Time complexity O(n)
// Space complexity O(n)
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> leftNSE(n, -1), rightNSE(n, -1);
    stack<int> leftStk, rightStk;
    int left = 0, right = n-1;
    while(left < n) {
        while(!leftStk.empty() && arr[leftStk.top()] >= arr[left]) {
            leftStk.pop();
        }
        if(!leftStk.empty()) {
            leftNSE[left] = leftStk.top();
        }
        leftStk.push(left);
        ++left;
    }
    // For handling duplicate case
    // We are calculating what is the next smaller element in the left side
    // And what is the next smaller or equal element in right side
    // If we don't do this then for duplicate element, we will count double 
    // [5 3 1 4 1 2] : for index 2 prev smaller index and next smaller index -1
    // for index 4 prev smaller index and next smaller index -1
    // So we are calculation 2 times when there is duplicate in array
    while(right >=0) {
        while(!rightStk.empty() && arr[rightStk.top()] > arr[right]) {
            rightStk.pop();
        }
        if(!rightStk.empty()) {
            rightNSE[right] = rightStk.top();
        }
        rightStk.push(right);
        --right;
    }

    // If an array has x+1+y element and x index (o based indexing) is val
    // then there will be (x+1) * (y+1) subarray which will contain val
    // subarray starting index [0 x] and ending index [x x+y]
    long totalSubarray = 0;
    int MOD = 1e9 + 7;
    unordered_set<int> uset;
    for(int i=0; i<n; ++i) {
        int leftSize = leftNSE[i] == -1 ? (i + 1) : (i - leftNSE[i]);
        int rightSize = rightNSE[i] == -1 ? (n - i) : (rightNSE[i] - i);
        totalSubarray = (totalSubarray + (long)leftSize * (long)rightSize * (long)arr[i]) % MOD;
    }
    return (int)totalSubarray;
}
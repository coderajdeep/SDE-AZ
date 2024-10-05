// Time complexity O(n)
// Space complexity O(n)

vector<int> findTwoElement(vector<int> arr, int n) {
    vector<int> hash(n+1, 0);
    for(int i=0; i<n; ++i) {
        hash[arr[i]]++;
    }
    vector<int> ans(2);
    bool flag1 = false, flag2 = false;
    for(int i=1; i<=n; ++i) {
        if(hash[i]==2) {
            ans[0] = i;
            flag1 = true;
        }
        else if(hash[i]==0) {
            ans[1] = i;
            flag2 = true;
        }
        if(flag1 && flag2) return ans;
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(1)
vector<int> findTwoElement(vector<int> arr, int n) {
    long val1 = 0, val2 = 0;
    for(int i=0; i<n; ++i) {
        val1 += (i+1-arr[i]);
        // Type casting
        val2 += (static_cast<long>(i+1)*static_cast<long>(i+1) - static_cast<long>(arr[i])*static_cast<long>(arr[i]));
    }
    int missing = (val1 + (val2/val1))/2;
    int repeat = missing - val1;
    return vector<int> {repeat, missing};
}
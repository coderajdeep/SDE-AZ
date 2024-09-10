// 33
// Union of two sorted array -- coding ninjas
// https://www.codingninjas.com/studio/problems/sorted-array_6613259

// Time complexity O(nlogn + mlogm + (n1 + n2))
// Space complexity O(2 * size of union array) [considering ans array as space complexity]
vector<int> sortedArray(vector<int>& a, vector<int>& b) {
    set<int> st;
    for(int element:a) {
        st.insert(element);
    }
    for(int element:b) {
        st.insert(element);
    }
    return vector<int> (st.begin(), st.end());
}

// Time complexity O(n+m)
// Space complexity O(size of union array) [considering ans array as space complexity]
vector <int> sortedArray(vector <int> a, vector <int> b) {
    int n = a.size();
    int m = b.size();
    int aIndex = 1, bIndex = 1;
    for(int i=1; i<n; ++i) {
        if(a[i-1]!=a[i]) {
            a[aIndex++] = a[i];
        }
    }
    for(int i=1; i<m; ++i) {
        if(b[i-1]!=b[i]) {
            b[bIndex++] = b[i];
        }
    }
    int i = 0, j = 0;
    vector<int> ans;
    while(i<aIndex && j<bIndex) {
        if(a[i]<b[j]) {
            ans.push_back(a[i]);
            ++i;
        }
        else if(a[i]==b[j]) {
            ans.push_back(a[i]);
            ++i;
            ++j;
        }
        else {
            ans.push_back(b[j]);
            ++j;
        }
    }
    while(i<aIndex) {
        ans.push_back(a[i++]);
    }
    while(j<bIndex) {
        ans.push_back(b[j++]);
    }
    return ans;
}
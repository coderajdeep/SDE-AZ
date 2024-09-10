// Array Can have duplicate elements
// Time complexity O(n+m)
// Space Complexity O(n+m)
// Space is used to store the answer not to calculate the answer
// Best approach
vector<int> sortedArray(vector<int>& a, vector<int>& b) {
    vector<int> ans;
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    while(i<n && j<m) {
        if(a[i]<=b[j]) {
            if(ans.empty() ||  (!ans.empty() && ans.back()!=a[i])) {
                ans.push_back(a[i]);
            }
            ++i;
        }
        else {
            if(ans.empty() ||  (!ans.empty() && ans.back()!=b[j])) {
                ans.push_back(b[j]);
            }
            ++j;
        }
    }

    while(i<n) {
        if(ans.empty() ||  (!ans.empty() && ans.back()!=a[i])) {
            ans.push_back(a[i]);
        }
        ++i;
    }
    while(j<m) {
        if(ans.empty() ||  (!ans.empty() && ans.back()!=b[j])) {
            ans.push_back(b[j]);
        }
        ++j;
    }
    return ans;
}

// Time complexity O((n+m)log(n+m) + (n+m))
// Space complexity O(n+m)
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

// Here we are removing the distinct element first
// Time complexity O(2*(n+m))
// Space Complexity O(n+m)
// Space is used to store the answer not to calculate the answer
vector<int> sortedArray(vector<int>& a, vector<int>& b) {
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
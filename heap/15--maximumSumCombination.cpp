// Time complexity O(nlogn) + O(klogk)
vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> st;
    pq.push({A[N-1] + B[N-1], {N-1, N-1}});
    st.insert({N-1, N-1});
    int index = 0;
    vector<int> ans(K);
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int sum = p.first;
        ans[index++] = sum;
        if(index==K) {
            return ans;
        }
        int i = p.second.first, j = p.second.second;
        if(st.find({i, j-1}) == st.end()) {
            pq.push({A[i]+B[j-1], {i, j-1}});
            st.insert({i, j-1});
        }
        if(st.find({i-1, j}) == st.end()) {
            pq.push({A[i-1]+B[j], {i-1, j}});
            st.insert({i-1, j});
        }
    }
    return ans;
}
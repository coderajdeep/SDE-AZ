// Rank Transform of an array -- leetcode 1331
// Uisng Min heap
// Best approach
// Solution 1
// Time complexity O(nlogn)
// Space complexity O(n)
vector<int> arrayRankTransform(vector<int>& arr) {
    if(arr.empty()) return vector<int>{};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n = arr.size();
    for(int i=0; i<n; ++i) {
        pq.push({arr[i], i});
    }
    vector<int> ans(n);
    int rank = 1, last = pq.top().first;
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        if(last != p.first) ++rank;
        ans[p.second] = rank;
        last = p.first;
    }
    return ans;
}

// Solution 2
// Time complexity O(nlogn)
// Space complexity O(n)
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arrs(n);
    for(int i=0; i<n; ++i) {
        arrs[i] = pair<int, int>{arr[i], i};
    }
    sort(arrs.begin(), arrs.end());
    vector<int> ans(n);
    int rank = 1;
    for(int i=0; i<n; ++i) {
        if(i==0 || (i>0 && arrs[i-1].first == arrs[i].first)) {
            ans[arrs[i].second] = rank;
        }
        else {
            ans[arrs[i].second] = ++rank;
        }
    }
    return ans;
}


// Using unordered_map
// Time complexity O(nlogn)
// Space complexity O(n)
vector<int> arrayRankTransform(vector<int>& arr) {
    int n = arr.size();
    vector<int> arrSorted(arr.begin(), arr.end());
    sort(arrSorted.begin(), arrSorted.end());
    unordered_map<int, int> ranks;
    int rank = 1;
    for(int i=0; i<n; ++i) {
        if(ranks.find(arrSorted[i]) == ranks.end()) {
            ranks[arrSorted[i]] = rank++;
        }
    }
    vector<int> ans(n);
    for(int i=0; i<n; ++i) {
        ans[i] = ranks[arr[i]];
    }
    return ans;
}
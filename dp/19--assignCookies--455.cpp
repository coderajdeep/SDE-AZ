// Time complexity O(min(n,m))
// Space complexity O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size();
    int m = s.size();
    int cnt = 0;
    for(int ni=0, mi=0; ni<n && mi<m; ) {
        if(g[ni]<=s[mi]) {
            ++cnt;
            ++ni;
            ++mi;
        }
        else {
            ++mi;
        }
    }
    return cnt;
}
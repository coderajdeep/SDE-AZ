// Assign cookies -- leetcode 455
// Time complexity O(nlogn + mlogm + max(n, m))
// Space complexity O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int n = g.size();
    int m = s.size();
    int ni = 0, mi = 0;
    for( ; ni<n && mi<m; ) {
        if(g[ni]<=s[mi]) {
            ++ni;
            ++mi;
        }
        else {
            ++mi;
        }
    }
    return ni;
}
// Time complexity O(2*n) + O(nlogn)
// Space complexity O(3*n)
struct COMP {
    bool operator()(const pair<int, char> &p1, const pair<int, char> &p2) const {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first > p2.first;
    }
};
string frequencySort(string s) {
    unordered_map<char, int> umap;
    for(char ch : s) {
        umap[ch]++;
    }
    int n = umap.size();
    set<pair<int, char>, COMP> st;
    for(pair<char, int> p : umap) {
        st.insert({p.second, p.first});
    }
    string ans;
    for(pair<int, char> p : st) {
        ans.append(p.first, p.second);
    }
    return ans;
}
// Longest common prefix -- leetcode 14
// Time complexity O(n*len(first string))
// Space complexity O(1)
// *** This question can be solved using Trie
// But needs to check the space complexity 
string lcp(string &s1, string &s2) {
    string s = "";
    int n1 = s1.size(), n2 = s2.size(), i = 0, j = 0;
    while(i<n1 && j<n2) {
        if(s1[i]==s2[j]) {
            s.push_back(s1[i]);
            ++i; 
            ++j;
        }
        else {
            break;
        }
    }
    return s;
}
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n==1) return strs[0];
    string s = "";
    int len = strs[0];
    for(int i=0; i<len; ++i) {
        for(int j=1; j<n; ++j) {
            if(strs[j].size()==i || strs[j])
        }
    }
    for(int i=2; i<n; ++i) {
        s = lcp(s, strs[i]);
        if(s.empty()) return s;
    }
    return s;
}

// solution 2
// uisng sorting
string lcp(string &s1, string &s2) {
    string s = "";
    int n1 = s1.size(), n2 = s2.size(), i = 0, j = 0;
    while(i<n1 && j<n2) {
        if(s1[i]==s2[j]) {
            s.push_back(s1[i]);
            ++i; 
            ++j;
        }
        else {
            break;
        }
    }
    return s;
}
string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n==1) return strs[0];
    sort(strs.begin(), strs.end());
    return lcp(strs[0], strs[n-1]);
}
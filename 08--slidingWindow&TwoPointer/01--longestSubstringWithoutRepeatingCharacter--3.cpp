// Longest substring without repeating character -- leetcode 3

// Solution 1
// https://youtu.be/-zSxTJkcdAo?t=594
// Best solution -- single traversal for any input
// Time complexity O(n)
// Space complexity O(256) : constant
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> umap;
    int n = s.size(), maxLen = 0, low = 0, high = 0;
    while(high<n) {
        auto it = umap.find(s[high]);
        if(it == umap.end() || it->second < low) {
            maxLen = max(maxLen, high-low+1);
        }
        // We can use both
        // else if(it->second >= low) {
        else {
            low = it->second + 1;
        }
        umap[s[high]] = high;
        ++high;
    }
    return maxLen;
}

// Solution 2
// Time complexity O(2*n)
// Space complexity O(256) : constant
// abcdefghii
// For this input, we need to traverse the entire string twice
int lengthOfLongestSubstring(string s) {
    int len = s.size(), low = 0, high = 0, maxLen = 0;
    unordered_set<char> uset;
    while(high < len) {
        if(uset.find(s[high]) == uset.end()) {
            maxLen = max(maxLen, high - low + 1);
            uset.insert(s[high]);
            ++high;
        }
        else {
            uset.erase(s[low]);
            ++low;
        }
    }
    return maxLen;
}

// Time complexity O(n*n)
// Space complexity O(256) : constant
int lengthOfLongestSubstring(string s) {
    int n = s.size(), len = 0;
    for(int i=0; i<n; ++i) {
        bool flag = true;
        unordered_set<char> uset;
        for(int j=i; j<n; ++j) {
            if(uset.find(s[j]) != uset.end()) {
                len = max(len, j - i);
                flag = false;
                break;
            }
            else {
                uset.insert(s[j]);
            }
        }
        if(flag) {
            len = max(len, n - i);
        }
    }
    return len;
}
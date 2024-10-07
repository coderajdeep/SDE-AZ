// Number of substring containing all three characters -- leetcode 1358

// Solution 1
// Best solution
// Time complexity O(n)
// Time complexity O(1)
int numberOfSubstrings(string s) {
    // In a, b, c we store the recent index of a, b, c
    // We have to find the smallest subarray where a, b, b exist and the subarray ends at current index
    // lets say subarray is [low high]
    // [0 high], [1 high], .. [low high]
    // total such subarray low + 1
    int a = -1, b = -1, c = -1, index = 0, count = 0, n = s.size();
    while(index<n) {
        if(s[index] == 'a') a = index;
        else if(s[index] == 'b') b = index;
        else if(s[index] == 'c') c = index;
        if(a!=-1 && b!=-1 && c!=-1) {
            int minStartIndex = min({a, b, c});
            count += (minStartIndex+1);
        }
        ++index;
    }
    return count;
}

// Solution 2
// Time complexity O(n)
// Time complexity O(1)
int numberOfSubstrings(string s) {
    int n = s.size(), low = 0, high = 0, count = 0;
    unordered_map<char, int> umap;
    while(high < n) {
        umap[s[high]]++;
        while(umap['a'] && umap['b'] && umap['c']) {
            count += (n - high);
            umap[s[low]]--;
            ++low;
        }
        ++high;
    }
    return count;
}
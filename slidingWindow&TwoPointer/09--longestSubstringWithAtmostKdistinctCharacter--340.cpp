// Longest substring with at most K distinct character -- leetcode 340

// Time complexity O(n)
// Space complexity O(k)
int lengthOfLongestSubstringKDistinct(string s, int k) {
    int low = 0, high = 0, maxLen = 0, n = s.size();
    unordered_map<char, int> umap;
    while(high < n) {
        umap[s[high]]++;
        while(low<=high && umap.size()>k) {
            umap[s[low]]--;
            if(umap[s[low]]==0) {
                umap.erase(s[low]);
            }
            ++low;
        }
        maxLen = max(maxLen, high - low + 1);
        ++high;
    }
    return maxLen;
}
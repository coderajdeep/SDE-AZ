// Minimum window substring -- leetcode 76
// Time complexity O(n)
// Space complexity O(unique element in target string)
string minWindow(string s, string t) {
    if(s.empty() || t.empty() || s.size() < t.size()) return "";
    if(s == t) return s;
    unordered_map<char, int> tmap, smap;
    int low = 0, high = 0, n = s.size(), minLength = INT_MAX, start = -1, end = -1;
    // frequency of target string
    for(char c : t) {
        tmap[c]++;
    }
    // neededCount --> total unique character
    int neededCount = tmap.size(), haveCount = 0;
    while(high < n) {
        // check if s[high] is in the target string or not
        if(tmap.find(s[high]) != tmap.end()) {
            smap[s[high]]++;
            // if s[high] count is equal in s and t then that character is sufficiently present
            if(smap[s[high]] == tmap[s[high]]) {
                ++haveCount;
            }
        }
        // when all unique character's are sufficiently present
        while(low<=high && haveCount == neededCount) {
            if((high - low + 1) < minLength) {
                minLength = high - low + 1;
                start = low;
                end = high;
            }
            smap[s[low]]--;
            // if s[low] is in the target string and smap[s[low]] < tmap[s[low]]
            if(tmap.find(s[low]) != tmap.end() && smap[s[low]] < tmap[s[low]]) {
                haveCount--;
            }
            ++low;
        }
        ++high;
    }
    return start != -1 ? s.substr(start, minLength) : "";
}
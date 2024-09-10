// Valid Anagram -- leetcode 242

// Solution 1
// Best solution
// Time complexity O(n)
// Space complexity O(26)
// This will only handle lower case english latter
bool isAnagram(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(n != m) return false;
    int hash[26] = {0};
    for(int i=0; i<n; ++i) {
        hash[s[i]-'a']++;
        hash[t[i]-'a']--;
    }
    for(int i=0; i<26; ++i) {
        if(hash[i]!=0) {
            return false;
        }
    }
    return true;
}

// Solution 2
// Time complexity O(n)
// Space complexity O(n)
// This solution can be handled any type of valid char in cpp
bool isAnagram(string s, string t) {
    unordered_multiset<char>ms;
    for(char& ch:s) {
        ms.insert(ch);
    }
    for(char& ch:t) {
        auto it = ms.find(ch);
        if(it!=ms.end()) {
        ms.erase(it);
        }
        else {
        return false;
        }
    }
    return ms.empty();
}

// Solution 3
// Time complexity O(nlogn)
// Space complexity O(1)
bool isAnagram(string& s, string& t) {
    int n1 = s.size();
    int n2 = t.size();
    if(n1!=n2) {
        return false;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i=0; i<n1; ++i) {
        if(s[i]!=t[i]) {
            return false;
        }
    }
    return true;
}
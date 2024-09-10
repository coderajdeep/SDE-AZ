// Longest Repeating character replacement -- leetcode 424

// Solution 1
// To understand this, watch solution 2
// Time optimization
// https://youtu.be/_eNhaDCr6P0?t=1263
// Time complexity O(26*n)
// Space complexity O(26)
int characterReplacement(string s, int k) {
    int left = 0, right = 0, n = s.size(), windowSize, maxFrequency = 0, maxLength = 0;
    int hash[26];
    while(right<n) {
        hash[s[right] - 'A']++;
        maxFrequency = max(maxFrequency, hash[s[right] - 'A']);
        if(((right-left+1)-maxFrequency)>k) {
            hash[s[left++] - 'A']--;
            for(int i=0; i<26; ++i) {
                maxFrequency = max(maxFrequency, hash[i]);
            }
        }
        // For getting maxLength, we only care about increasing window size value
        // We don't want to decrease maxFrequency value
        // because then for getting valid window, we need to decrease the window size
        if(((right-left+1)-maxFrequency)<=k) {
            maxLength = max(maxLength, (right-left+1));
        }
        ++right;
    }
    return maxLength;
}

// Solution 2
// Time complexity O(2*n*26)
// Space complexity O(26)
int characterReplacement(string s, int k) {
    int left = 0, right = 0, n = s.size(), windowSize, maxFrequency = 0, maxLength = 0;
    unordered_map<char, int> hash;
    while(right<n) {
        hash[s[right]]++;
        maxFrequency = max(maxFrequency, hash[s[right]]);
        while(((right-left+1)-maxFrequency)>k) {
            hash[s[left++]]--;
            for(pair<char, int> p : hash) {
                maxFrequency = max(maxFrequency, p.second);
            }
        }
        if(((right-left+1)-maxFrequency)<=k) {
            maxLength = max(maxLength, (right-left+1));
        }
        ++right;
    }
    return maxLength;
}

// Time complexity O(n*26)
// Space complexity O(26)
int characterReplacement(string s, int k) {
    int left = 0, right = 0, n = s.size(), windowSize, maxFrequency = 0, maxLength = 0;
    unordered_map<char, int> hash;
    while(right<n) {
        hash[s[right]]++;
        maxFrequency = max(maxFrequency, hash[s[right]]);
        if(((right-left+1)-maxFrequency)>k) {
            hash[s[left++]]--;
            for(pair<char, int> p : hash) {
                maxFrequency = max(maxFrequency, p.second);
            }
        }
        if(((right-left+1)-maxFrequency)<=k) {
            maxLength = max(maxLength, (right-left+1));
        }
        ++right;
    }
    return maxLength;
}

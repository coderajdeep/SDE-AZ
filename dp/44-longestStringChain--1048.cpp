class Solution {
public:
    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    bool isChain(string &s1, string &s2) {
        // word in words are sorted based on length of word
        // so n1 < n2
        int n1 = s1.size();
        int n2 = s2.size();
        if(n2-n1 != 1) return false;
        int i = 0, j = 0, count = 0;
        while(i<n1) {
            if(s1[i] != s2[j]) {
                ++j;
                ++count;
                // abcd
                // abxyd
                if(count>1) return false;
            }
            else {
                ++i;
                ++j;
            }
        }
        // abc abcd
        return (n1==i);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size(), maxLen = 1;
        // sort based on length of word
        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        for(int curr = 1; curr<n; ++curr) {
            for(int prev=0; prev<curr; ++prev) {
                if(isChain(words[prev], words[curr]) && dp[prev]+1 > dp[curr]) {
                    dp[curr] = 1 + dp[prev];
                }
            }
            if(maxLen < dp[curr]) maxLen = dp[curr];
        }
        return maxLen;
    }
};
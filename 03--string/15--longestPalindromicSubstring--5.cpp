// Solution 2
// Expanding from center
// Time complexity O(n*n)
// Space complexity O(1) 
// For returning the answer we have used substr which use O(n) space
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), start, maxLen = 0, len;
        for(int i=0; i<n; ++i) {
            // for odd length palindrome
            int left = i, right = i;
            while(left>=0 && right<n && s[left]==s[right]) {
                len = (right - left + 1);
                if(maxLen < len) {
                    maxLen = len;
                    start = left;
                }
                --left;
                ++right;
            }
            // for even length palindrome
            left = i, right = i+1;
            while(left>=0 && right<n && s[left]==s[right]) {
                len = (right - left + 1);
                if(maxLen < len) {
                    maxLen = len;
                    start = left;
                }
                --left;
                ++right;
            }
        }
        return s.substr(start, maxLen);
    }
};

// Solution 3
// Dynamic programming solution
// Time complexity O(n*n)
// Space complexity O(n*n) 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 1, start = 0;
        bool dp[n][n];
        dp[0][0] = true;
        for(int i=1; i<n; ++i) {
            dp[i][i] = true;
            if(s[i-1]==s[i]) {
                dp[i-1][i] = true;
                if(maxLen < 2) {
                    start = i-1;
                    maxLen = 2;
                }
            }
            else {
                dp[i-1][i] = false;
            }
        }
        int col = 2;
        while(col<n) {
            int i = 0;
            int j = col;
            while(i<n && j<n) {
                if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = false;
                if(dp[i][j] && maxLen < (j-i+1)) {
                    start = i;
                    maxLen = (j-i+1);
                }
                ++i;
                ++j;
            }
            ++col;
        }
        return s.substr(start, maxLen);
    }
};
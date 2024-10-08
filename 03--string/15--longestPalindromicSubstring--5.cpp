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
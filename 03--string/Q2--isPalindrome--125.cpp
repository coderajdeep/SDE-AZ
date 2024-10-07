// Time complexity O(n)
// Space complexity O(1)
bool isValid(char ch) {
    return isalpha(ch) || isdigit(ch);
}
bool isPalindrome(string s) {
    int left = 0, right = s.size()-1;
    while(left<right) {
        if(!isValid(s[left])) {
            ++left;
        }
        else if(!isValid(s[right])) {
            --right;
        }
        else if(isdigit(s[left]) && isdigit(s[right])) {
            if(s[left]!=s[right]) {
                return false;
            }
            ++left;
            --right;
        }
        else {
            if(toupper(s[left])!=toupper(s[right])) {
                return false;
            }
            ++left;
            --right;
        }
    }
    return true;
}

// Recursive approach
// Time complexity O(n)
// Space complexity O(n) [recursive stack space]
bool isValid(char ch) {
    return isalpha(ch) || isdigit(ch);
}
bool isTrue(int start, int end, string &s) {
    if(start>=end) return true;
    if(!isValid(s[start])) return isTrue(start+1, end, s);
    if(!isValid(s[end])) return isTrue(start, end-1, s);
    if(isdigit(s[start]) && isdigit(s[end])) return s[start]==s[end] && isTrue(start+1, end-1, s);
    return (tolower(s[start])==tolower(s[end])) && isTrue(start+1, end-1, s);
}
bool isPalindrome(string s) {
    return isTrue(0, s.size()-1, s);
}
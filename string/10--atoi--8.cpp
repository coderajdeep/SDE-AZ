// Time complexity O(n)
// Space complexity O(1)
int getSign(string &s, int &index) {
    int n = s.size();
    // removing whitespace
    for(; index<n; ++index) {
        if(s[index] != ' ') break;
    }
    if(s[index] == '-') {
        ++index;
        return -1;
    }
    else if(s[index] == '+') {
        ++index;
        return 1;
    }
    return 1;
}
bool isNumber(char &ch) {
    if(ch>='0' && ch<='9') return true;
    return false;
}

int myAtoi(string s) {
    int n = s.size(), index = 0;
    int sign = getSign(s, index);
    long ans = 0;
    for(; index<n; ++index) {
        if((sign * ans) > INT_MAX) return INT_MAX;
        else if((sign * ans) < INT_MIN) return INT_MIN;
        else if(isNumber(s[index])) {
            ans = (ans * 10) + (s[index] - '0');
        }
        else break;
    }
    if((sign * ans) > INT_MAX) return INT_MAX;
    else if((sign * ans) < INT_MIN) return INT_MIN;
    return (sign * ans);
}
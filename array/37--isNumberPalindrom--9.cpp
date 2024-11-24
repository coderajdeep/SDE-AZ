// leetcode 9
// Check if an number is palindrom or not

// By reversing the number
bool isPalindrome(int x) {
    if(x<0) {
        return false;
    }
    int num = x, ans = 0;
    int intMax = INT_MAX/10;
    while(num) {
        if(ans>intMax) {
            return false;
        }
        ans = (ans*10) + (num%10);
        num = num/10;
    }
    return ans == x;
}

// By converting the number into string
string int2string(int num) {
    if(num == 0) {
        return "0";
    }
    string s;
    if(num<0) {
        num = -num;
        s.push_back('-');
    }
    while(num>0) {
        int lastDigit = num%10;
        char ch = lastDigit + '0';
        s.push_back(ch);
        num /= 10;
    }
    return s;
}
bool isPalindrome(int x) {
    if(x<0) {
        return false;
    }
    string s = int2string(x);
    int low = 0, high = s.size()-1;
    
    while(low<high) {
        if(s[low++]!=s[high--]) {
            return false;
        }
    }
    return true;
}
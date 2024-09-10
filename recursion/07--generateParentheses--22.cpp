// Solution 1
// Solution 1 and 2 are similar
// Tracking count of opening and closing parentheses
// open < close
// above condition will never occur
// Time complexity O(2^n)
// Time complexity will be less than this
// As we will eleminate lots of string based on open and close count
// Space complexity O(2^n) [for storing max 2^n string] + O(2*n) [for storing the string which is used for backtracking]
// Recursive stack space O(2*n)
void solve(int index, int n, int open, int close, string &str, vector<string> &ans) {
    if(index == (2*n)) {
        if(open == close) {
            ans.push_back(str);
        }
        return;
    }
    if(close > open || open > n) return;
    if(index == 0) {
        str[0] = '(';
        solve(1, n, 1, 0, str, ans);
    }
    else {
        str[index] = '(';
        solve(index + 1, n, open + 1, close, str, ans);
        str[index] = ')';
        solve(index + 1, n, open, close + 1, str, ans);
    }
}
vector<string> generateParenthesis(int n) {
    string str(2*n, ' ');
    vector<string> ans;
    solve(0, n, 0, 0, str, ans);
    return ans;
}

// Solution 2
void utils(int index, int open, int close, int N, string &str, vector<string> &ans) {
    if(index==N || open < close) {
        if(open==close) {
            ans.push_back(str);
        }
        return;
    }
    if(open > close) {
        str[index] = '(';
        utils(index+1, open + 1, close, N, str, ans);
        str[index] = ')';
        utils(index+1, open, close + 1, N, str, ans);
    }
    else if(open == close) {
        str[index] = '(';
        utils(index+1, open + 1, close, N, str, ans);
    }
}
vector<string> generateParenthesis(int n) {
    int N = 2 * n;
    string str(N, ' ');
    vector<string> ans;
    utils(0, 0, 0, 2 * n, str, ans);
    return ans;
}

// Solution 3
// Brute fource
// Generate Parentheses -- leetcode 22
// Generating 2^n number of parenthesis and checking their validation
// Time complexity O(n * 2^n)
// Space complexity O(2^n + n)
bool isValid(string &s) {
    int n = s.size();
    stack<char> stk;
    for(int i=0; i<n; ++i) {
        if(s[i]=='(') {
            stk.push(s[i]);
        }
        else if(stk.empty()) {
            return false;
        }
        else if(stk.top()=='(' && s[i]==')') {
            stk.pop();
        }
    }
    return stk.empty();
}
void utils(int index, int n, string &s, vector<string> &ans) {
    if(index==n) {
        if(isValid(s)) {
            ans.push_back(s);
        }
        return;
    }
    s[index] = '(';
    utils(index+1, n, s, ans);
    s[index] = ')';
    utils(index+1, n, s, ans);
}
vector<string> generateParenthesis(int n) {
    int N = 2*n;
    string s(N, ' ');
    vector<string> ans;
    utils(0, N, s, ans);
    return ans;
}
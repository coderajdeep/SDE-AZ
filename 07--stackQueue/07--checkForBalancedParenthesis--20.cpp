// Checked for balanced paranthesis -- leetcode 20

// Time complexity O(n)
// Space complexity O(n)
bool isValid(string s) {
    stack<char>stk;
    
    for(const char ch:s) {
        // whenever any open bracket then push to stack
        if(ch=='(' || ch=='{' || ch=='[')
            stk.push(ch);
        
        // ch is not open bracket and stk.empty() then string can't be balanced
        else if(stk.empty())
            return false;
        
        // ch == '('  stk.top() == ')'
        // '()' balance
        // we need to pop()
        else if(ch==')' && stk.top()=='(')
            stk.pop();
        
        // ch == '{'  stk.top() == '}'
        // '{}' balance
        // we need to pop()
        else if(ch=='}' && stk.top()=='{')
            stk.pop();
        
        // ch == '['  stk.top() == ']'
        // '[]' balance
        // we need to pop()
        else if(ch==']' && stk.top()=='[')
            stk.pop();
        
        // (), {}, [] must be miss matched
        else
            return false;
    }
    
    return stk.empty();
}

// Time complexity O(n)
// Space complexity O(1)
// Given string will be modified
// https://youtu.be/aoYm3bmOPHw (Time O(n^2) space O(1))
bool isValid(string s) {
    int n = s.size(), index = -1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            s[++index] = s[i];
        }
        else if(index>=0) {
            if((s[index]=='(' && s[i]==')') || (s[index]=='{' && s[i]=='}') || (s[index]=='[' && s[i]==']')) {
                --index;
            }
            else {
                return false;
            }
        }
        else {
            // index == -1
            return false;
        }
    }
    return (index==-1);
}
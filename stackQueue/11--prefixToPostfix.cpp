// Prefix to postfix -- coding ninjas

string preToPost(string s) {
    stack<string> stk;
    int n = s.size();
    for(int i=n-1; i>=0; --i) {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) {
            stk.push(string(1, s[i]));
        }
        else {
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();
            string temp = op1 + op2 + s[i];
            stk.push(temp);
        }
    }
    return stk.top();
}
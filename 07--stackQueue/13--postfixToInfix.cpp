// Postfix to Infix -- coding ninjas

string postToInfix(string postfix) {
    stack<string> stk;
    for(const char ch : postfix) {
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')) {
            stk.push(string(1, ch));
        }
        else {
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();
            string temp = '(' + op1 + ch + op2 + ')';
            stk.push(temp);
        }
    }
    return stk.top();
}
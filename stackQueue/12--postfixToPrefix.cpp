// Postfix to prefix -- coding ninjas

string postfixToPrefix(string &s){
    stack<string> stk;
    for(const char ch : s) {
        if(ch>='a' && ch<='z') {
            stk.push(string(1, ch));
        }
        else {
            string op2 = stk.top();
            stk.pop();
            string op1 = stk.top();
            stk.pop();
            string temp = ch + op1 + op2;
            stk.push(temp);
        }
    }
    return stk.top();
}
// Prefix to infix expression -- coding ninjas

string prefixToInfixConversion(string &s){
	stack<string> stk;
	int n = s.size();
	for(int i=n-1; i>=0; --i) {
		if(s[i]>='a' && s[i]<='z') {
			stk.push(string(1, s[i]));
		}
		else {
			string operand1 = stk.top();
			stk.pop();
			string operand2 = stk.top();
			stk.pop();
			string temp = '(' + operand1 + s[i] + operand2 + ')';
			stk.push(temp);
		}
	}
	return stk.top();
}

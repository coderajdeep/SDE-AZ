// Infix to Postfix Expression

int prec(char& ch) {
	if(ch=='+' || ch=='-') {
		return 1;
	}
	else if(ch=='*' || ch=='/') {
		return 2;
	}
	else if(ch=='^') {
		return 3;
	}
	else {
		return 0;
	}
}
string infixToPostfix(string& exp){
	stack<char> stk;
	string postfix;
	for(char ch : exp) {
		if((ch>='0' && ch<='9') || (ch>='a' && ch<='z')) {
			postfix.push_back(ch);
		}
		else if(ch=='(') {
			stk.push(ch);
		}
		else if(ch==')') {
			while(!stk.empty() && stk.top()!='(') {
				postfix.push_back(stk.top());
				stk.pop();
			}
			stk.pop();
		}
		else {
			// If the character is operator
			while(!stk.empty() && (prec(ch)<=prec(stk.top()))) {
				postfix.push_back(stk.top());
				stk.pop();
			}
			stk.push(ch);
		}
	}
	while(!stk.empty()) {
		postfix.push_back(stk.top());
		stk.pop();
	}
	return postfix;
}
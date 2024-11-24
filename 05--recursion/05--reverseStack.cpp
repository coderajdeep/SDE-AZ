// Geeks
// Time complexity O(n*n)
// Space complexity O(n)

void insert(stack<int> &stk, int temp) {
    if(stk.empty()) {
        stk.push(temp);
        return;
    }
    int val = stk.top();
    stk.pop();
    insert(stk, temp);
    stk.push(val);
}
void Reverse(stack<int> &stk){
    if(stk.empty() || stk.size()==1) {
        return;
    }
    int temp = stk.top();
    stk.pop();
    Reverse(stk);
    insert(stk, temp);
}
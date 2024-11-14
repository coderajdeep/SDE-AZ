// Remove K digits -- leetcode 402

// Time complexity O(n)
// Space complexity O(n)
// About edge case
// https://youtu.be/3QJzHqNAEXs?t=793
string removeKdigits(string num, int k) {
    stack<char> stk;
    for(char ch : num) {
        while(!stk.empty() && k>0 && (stk.top() > ch)) {
            stk.pop();
            --k;
        }
        if(!stk.empty() || ch != '0') stk.push(ch);
    }
    while(!stk.empty() && k > 0) {
        stk.pop();
        --k;
    }
    int size = stk.size();
    string ans(size, '0');
    for(int i=size-1; i>=0; --i) {
        ans[i] = stk.top();
        stk.pop();
    }
    return size ? ans : "0";
}
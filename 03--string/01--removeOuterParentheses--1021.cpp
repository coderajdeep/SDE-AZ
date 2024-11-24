// Solution 1
// Best solution
// Time complexity O(n)
// Space complexity O(n)
string removeOuterParentheses(string s) {
    int cnt = 0;
    string ans = "";
    for(char ch : s) {
        if(cnt == 0) {
            ++cnt;
        }
        else if(cnt > 0) {
            if(ch == '(') {
                ++cnt;
            }
            else {
                --cnt;
            }
            if(cnt) {
                ans.push_back(ch);
            }
        }
    }
    return ans;
}
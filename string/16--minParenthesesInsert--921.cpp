// Time complexity O(n)
// Space complexity O(1)
// "())"
// "((("
// "()(())(((()("
// edge case "()))(("
int minAddToMakeValid(string s) {
    int cnt = 0, ans = 0;
    for(char ch : s) {
        if(ch=='(') {
            if(cnt>=0) ++cnt;
            else {
                ans += abs(cnt);
                cnt = 1;
            }
        }
        else {
            --cnt;
        }
    }
    return ans + abs(cnt);
}
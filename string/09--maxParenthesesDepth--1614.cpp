// Time complexity O(n)
// Space complexity O(1)
int maxDepth(string s) {
    int ans = 0, cnt = 0;
    for(char ch : s) {
        if(ch=='(') {
            ++cnt;
            ans = max(ans, cnt);
        }
        else if(ch==')') {
            --cnt;
        }
    }
    return ans;
}
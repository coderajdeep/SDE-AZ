// Evaluate boolean expression to true -- Coding Ninjas
// Time complexity O(n*n*n*2)
// Space complexity O(n*n*2) + Recursion Stack space O(n)
const int mod = 1e9 + 7;
int getTotalTrue(int start, int end, int isTrue, string &exp, vector<vector<vector<int>>> &dp) {
    if(start>end) return 0;
    if(start==end) {
        if(isTrue==1) return exp[start]=='T' ? 1 : 0;
        else return exp[start]=='F' ? 1 : 0;
    }
    if(dp[start][end][isTrue] != -1) return dp[start][end][isTrue];
    long long count = 0;
    for(int index = start+1; index<=end-1; index += 2) {
        long long n1 = getTotalTrue(start, index-1, 1, exp, dp);
        long long n2 = getTotalTrue(start, index-1, 0, exp, dp);
        long long n3 = getTotalTrue(index+1, end, 1, exp, dp);
        long long n4 = getTotalTrue(index+1, end, 0, exp, dp);
        if(isTrue==1) {
            if(exp[index]=='&') {
                count += (n1*n3)%mod;
            }
            else if(exp[index]=='^') {
                count += ((n1*n4)%mod + (n2*n3)%mod)%mod;
            }
            else if(exp[index]=='|') {
                count += ((n1*n3)%mod + (n1*n4)%mod + (n2*n3)%mod)%mod;
            }
        }
        else {
            if(exp[index]=='&') {
                count += ((n1*n4)%mod + (n2*n3)%mod + (n2*n4)%mod)%mod;
            }
            else if(exp[index]=='^') {
                count += ((n1*n3)%mod + (n2*n4)%mod)%mod;
            }
            else if(exp[index]=='|') {
                count += (n2*n4)%mod;
            }
        }
    }
    return dp[start][end][isTrue] = (count%mod);
}

int evaluateExp(string & exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
    return getTotalTrue(0, exp.size()-1, 1, exp, dp);
}
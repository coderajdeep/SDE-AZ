// Gererate all binary string without consecutive 1's -- Geeks
// If we need to find the count then its a imp DP question
// Time complexity O(2^n)
// Space complexity O(2^n) [for storing max 2^n string] + O(n) [for storing the string which is used for backtracking] +
// Recursive stack space O(n)
void utils(int index, int N, string &s, vector<string> &ans) {
    if(index==N) {
        ans.push_back(s);
        return;
    }
    if(index==0) {
        s[0] = '0';
        utils(1, N, s, ans);
        s[0] = '1';
        utils(1, N, s, ans);
    }
    else if(s[index-1]=='1') {
        s[index] = '0';
        utils(index+1, N, s, ans);
    }
    else {
        s[index] = '0';
        utils(index+1, N, s, ans);
        s[index] = '1';
        utils(index+1, N, s, ans);
    }
}

vector<string> generateString(int N) {
    vector<string> ans;
    string s(N, '#');
    utils(0, N, s, ans);
    return ans;
}
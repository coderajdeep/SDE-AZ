// Time complexity O(n*m) + O(n+m)
// Space complexity O(n*m)

string findLCS(int n, int m, string &s1, string &s2){
	int dp[n+1][m+1];
	for(int i=0; i<=n; ++i) dp[i][0] = 0;
	for(int i=0; i<=m; ++i) dp[0][i] = 0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=m; ++j) {
			if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	string str(dp[n][m], '#');
	int i=n, j=m, index = (dp[n][m]-1);
	while(i>0 && j>0 && index>=0) {
		if(s1[i-1]==s2[j-1]) {
			str[index--] = s1[i-1];
			i = i-1;
			j = j-1;
		}
		else {
			if(dp[i][j-1] < dp[i-1][j]) {
				i = i-1;
			}
			else {
				j = j-1;
			}
		}
	}
	return str;
}


// Geeks
// Need to optimized later
class Solution {
  public:
    void solve(int i, int j, string &s, string &t, string str, unordered_set<string> &hash, vector<vector<int>> &dp) {
        if(i==0 || j==0) {
            hash.insert(str);
            return;
        }
        if(s[i-1]==t[j-1]) {
            str.push_back(s[i-1]);
            solve(i-1, j-1, s, t, str, hash, dp);
        }
        else if(dp[i-1][j] == dp[i][j-1]) {
            solve(i, j-1, s, t, str, hash, dp);
            solve(i-1, j, s, t, str, hash, dp);
        }
        else if(dp[i-1][j] < dp[i][j-1]) {
            solve(i, j-1, s, t, str, hash, dp);
        }
        else {
            solve(i-1, j, s, t, str, hash, dp);
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i=0; i<=n; ++i) {
            for(int j=0; j<=m; ++j) {
                if(i==0 || j==0) {
                    dp[i][j] = 0;
                }
                else if(s[i-1]==t[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    dp[i][j] = max(up, left);
                }
            }
        }
        string str = "";
        vector<string> ans;
        unordered_set<string> hash;
        solve(n, m, s, t, str, hash, dp);
        for(string st : hash) {
            reverse(st.begin(), st.end());
            ans.push_back(st);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
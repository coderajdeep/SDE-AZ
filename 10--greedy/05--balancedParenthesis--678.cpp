// https://youtu.be/cHT6sG_hUZI
// If there is no '*' then for finding balanced parenthesis
// We need to increase count for '(' and decrease count for ')'
// if any point count is negative then string is not balanced
// at the end if count is positive then string is not balanced
// when string have '*' then we need to take the count range

// Time complexity O(n)
// Space complexity O(1)

// (**(
// Dry run this test case
bool checkValidString(string s) {
    int n = s.size(), minCount = 0, maxCount = 0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='(') {
            ++minCount;
            ++maxCount;
        }
        else if(s[i]==')') {
            minCount = max(--minCount, 0);
            if((--maxCount)<0) return false;
        }
        else {
            minCount = max(--minCount, 0);
            ++maxCount;
        }
    }
    return min(maxCount, minCount) == 0;
}


// Time complexity O(n*n)
// Space complexity O(n)
class Solution {
public:
    int isValid(int index, int count, string &s, vector<vector<int>> &dp) {
        if(count<0) return 0;
        if(index == s.size()) {
            if(count==0) return 1;
            else return 0;
        }
        if(dp[index][count] != -1) return dp[index][count];
        if(s[index]=='(') {
            return dp[index][count] = isValid(index+1, count+1, s, dp);
        }
        else if(s[index]==')') {
            return dp[index][count] = isValid(index+1, count-1, s, dp);
        }
        return dp[index][count] = (isValid(index+1, count-1, s, dp) || isValid(index+1, count+1, s, dp) || isValid(index+1, count, s, dp));
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return isValid(0, 0, s, dp);
    }
};
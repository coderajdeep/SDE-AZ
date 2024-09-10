// https://youtu.be/cHT6sG_hUZI
// If there is no '*' then for finding balanced parenthesis
// We need to increase count for '(' and decrease count for ')'
// if any point count is negative then string is not balanced
// at the end if count is positive then string is not balanced
// when string have '*' then we need to take the count range

// Time complexity O(n)
// Space complexity O(1)
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
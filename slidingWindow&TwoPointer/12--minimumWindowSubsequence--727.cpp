// Minimum window subsequence -- leetcode 727

// Time complexity O(n*m)
// Space complexity O(1) or O(answer length)
// Space is only used for returning string
string minWindow(string s1, string s2) {
    int n = s1.size(), m = s2.size(), s2_index = 0, start, end, startIndex;
    int minLength = n + 1;

    for(int s1_index = 0; s1_index < n; ++s1_index) {
        if(s1[s1_index] == s2[s2_index]) {
            s2_index++;
        }
        if(s2_index == m) {
            start = end = s1_index;
            s2_index--;
            while(s2_index >= 0) {
                if(s1[start] == s2[s2_index]) {
                    --s2_index;
                }
                --start;
            }
            ++start;
            if(end - start + 1 < minLength) {
                startIndex = start;
                minLength = end - start + 1;
            }
            s2_index = 0;
            s1_index = start;
            // in next iteration s1_index will be start+1
            // which means next subsequence look up will be started from start+1 index
        }
    } 
    return (minLength == n + 1) ? "" : s1.substr(startIndex, minLength);
}
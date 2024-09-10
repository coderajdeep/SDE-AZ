// given string : s --> [a+b]
// rotation of s : goal --> [b+a]
// updated string --> s + s --> str --> [a+b+a+b]
// so by this observation, we can say that goal will be a substring of str if we rotate s
// Time complexity O(n*m)
// Space complexity O(n*m)
bool rotateString(string s, string goal) {
    if(s.size() != goal.size()) {
        return false;
    }
    string str = (s + s);
    // find time complexity O(n*m)
    if(str.find(goal) != -1) {
        return true;
    }
    return false;
}
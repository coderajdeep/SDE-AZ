// solution 1
// Time complexity O(n)
// Space complexity O(1)
// Here we are modifying the given string
string largestOddNumber(string num) {
    int n = num.size();
    for(int i=n-1; i>=0; --i) {
        if((num[i]-'0') & 1) {
            return num;
        }
        num.pop_back();
    }
    return "";
}
// solution 2
// Time complexity O(n)
// Space complexity O(n)
string largestOddNumber(string num) {
    int n = num.size();
    for(int i=n-1; i>=0; --i) {
        if((num[i]-'0') & 1) {
            return num.substr(0, i+1);
        }
    }
    return "";
}
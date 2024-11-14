// 1
// Reverse Words in a string - leetcode 151

// Time complexity O(n)
// Space complexity O(n)
// Without using stack
void reverseString(int low, int high, string& s) {
    while(low<=high) {
        swap(s[low++], s[high--]);
    }
}
string reverseWords(string s) {
    int len = s.size();
    reverseString(0, len-1, s);
    string str, ans;
    for(int i=0; i<len; ++i) {
        if(s[i]!=' ') {
            str.push_back(s[i]);
        }
        else if(str.size()) {
            reverseString(0, str.size()-1, str);
            ans.append(str);
            ans.push_back(' ');
            str.clear();
        }
    }
    if(str.size()) {
        reverseString(0, str.size()-1, str);
        ans.append(str);
        ans.push_back(' ');
        str.clear();
    }
    if(ans.size()) {
        ans.pop_back();
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
string reverseWords(string& s) {
    stack<string>words;
    string word;
    int n = s.size();
    for(int i=0; i<n; ++i) {
        if(s[i]!=' ') {
            word.push_back(s[i]);
        }
        else if(!word.empty()) {
            words.push(word);
            word.clear();
        }
    }
    if(!word.empty()) {
        words.push(word);
        word.clear();
    }
    string ans;
    while(!words.empty()) {
        ans.append(words.top());
        words.pop();
        ans.push_back(' ');
    }
    if(!ans.empty()) {
        ans.pop_back();
    }
    return ans;
}

// Same time complexity as above
string reverseWords(string s) {
    int n = s.size();
    if(n==0) return "";
    
    string st;
    stack<string> stk;
    
    for(int i=0; i<n; ++i) {
        if(s[i]!=' ') st.push_back(s[i]);
        
        else if(st.size()) {
            stk.push(st);
            st.clear();
        }
    }
    if(st.size()) {
        stk.push(st);
        st.clear();
    }
    
    while(!stk.empty()) {
        st += stk.top();
        stk.pop();
        if(!stk.empty()) st += " ";
    }
    
    return st;

}
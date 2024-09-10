bool isVowel(char ch) {
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
string removeVowels(string s) 
{
    int n = s.size(), index = 0;
    for(int i=0; i<n; ++i) {
        if(!isVowel(s[i])) {
            swap(s[i], s[index++]);
        }
    }
    for(int i=n-1; i>=index; --i) {
        s.pop_back();
    }
    return s;
}
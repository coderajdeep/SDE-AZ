
// Time complexity O(n)
// Space complexity O(2*256)
bool isIsomorphic(string s, string t) {
    int hash1[256];
    int hash2[256];
    for(int i=0; i<256; ++i) {
        hash1[i] = -1;
        hash2[i] = -1;
    }
    int n = s.size(); // s and t length are equal
    for(int i=0; i<n; ++i) {
        int target = t[i];
        int value = s[i];
        if(hash1[value] == -1) {
            hash1[value] = target; 
        }
        else if(hash1[value] != target) {
            return false;
        }
        if(hash2[target] == -1) {
            hash2[target] = value; 
        }
        else if(hash2[target] != value) {
            return false;
        }
    }
    return true;
}
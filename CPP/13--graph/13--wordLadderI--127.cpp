// Word Ladder 1 -- leetcode 127
// Time complexity O(n*size*26)
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int size = endWord.size();
    if(size != beginWord.size()) return 0;
    unordered_set<string> uset;
    for(string word : wordList) {
        uset.insert(word);
    }
    if(uset.find(endWord) == uset.end()) return 0;
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    uset.erase(beginWord);
    while(!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        string str = p.first;
        int dist = p.second + 1;
        
        for(int i=0; i<size; ++i) {
            for(int j=0; j<26; ++j) {
                str[i] = (int)'a' + j;
                if(str == endWord) return dist;
                auto it = uset.find(str);
                if(str != p.first && it != uset.end()) {
                    q.push({str, dist});
                    uset.erase(it);
                } 
            }
            str = p.first;
        }
    }
    return 0;
}
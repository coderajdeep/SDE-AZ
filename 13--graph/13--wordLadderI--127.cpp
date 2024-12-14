// Word Ladder 1 -- leetcode 127
// Time complexity O(n*size*26)
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int size = endWord.size();
    if(size != beginWord.size()) return 0;
    unordered_set<string> uset;
    for(string word : wordList) {
        uset.insert(word);
    }
    if(uset.find(endWord) == uset.end()) {
        return 0;
    }
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    auto it = uset.find(beginWord);
    if(it != uset.end()) uset.erase(it);

    while(!q.empty()) {
        pair<string, int> p = q.front();
        q.pop();
        string word = p.first;
        if(word==endWord) {
            return p.second;
        }
        string updatedString = word;
        for(int i=0; i<size; ++i) {
            for(char ch='a'; ch<='z'; ++ch) {
                if(ch != word[i]) {
                    updatedString[i] = ch;
                    auto it = uset.find(updatedString);
                    if(it != uset.end()) {
                        uset.erase(it);
                        q.push({updatedString, p.second + 1});
                    }
                }
            }
            updatedString[i] = word[i];
        }
    }

    return 0;
}
// Given a string which have words seperated by space. Need to find how many anagrams are there. 
// If same words appear multiple times then we need to ignore that count.
// Example : "dog aa ogd aa god"
// Answer : 2 (dog --> ogd and god)

int CountingAnagrams(string str) {
    unordered_map<string, int> ags;
    unordered_set<string> distWords;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        distWords.insert(word);
    }
    
    for(string word : distWords) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        ags[sortedWord]++;
    }
    
    int cnt = 0;
    for (const auto& pair : ags) {
        if (pair.second > 1) {
            cnt += (pair.second-1);
        }
    }
    
    return cnt;
}
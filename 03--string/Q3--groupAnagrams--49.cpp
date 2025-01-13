// Group anagrams - leetcode 49
// Need to group all of the anagrams

// Time complexity O(n*m*m*log(m))
// Space complexity O(n*m)

// m --> string length
// n --> vector length

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for(string str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            umap[sortedStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(pair<string, vector<string>> p : umap) {
            ans.push_back(p.second);
        }
        return ans;
    }
};
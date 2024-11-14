// Solution 1
// Best solution
// Time complexity O(2*n)
// Space complexity O(1)
long long int atMostK(string &s, int k) {
    long long n = s.size(), high = 0, low = 0, count = 0, ans = 0;
    long long hash[26] = {0};
    while(high<n) {
        int currChar = s[high]-'a';
        hash[currChar]++;
        if(hash[currChar]==1) ++count;
        while(count>k) {
            int lowChar = s[low]-'a';
            hash[lowChar]--;
            if(hash[lowChar]==0) --count;
            ++low;
        }
        ans += (high-low+1);
        ++high;
    }
    return ans;
}
long long int substrCount (string s, int k) {
    return atMostK(s, k) - atMostK(s, k-1);
}

// Solution 2
// Time complexity O(2*n)
// Space complexity O(1)
long long int substrCountUtils (string &s, int k) {
    if(k<=0) return 0;
    long long low = 0, high = 0, count = 0, n = s.size();
    unordered_map<char, long long> umap;
    while(high<n) {
        umap[s[high]]++;
        while(low<=high && umap.size()>k) {
            umap[s[low]]--;
            if(umap[s[low]]==0) {
                umap.erase(s[low]);
            }
            ++low;
        }
        count += (high-low+1);
        ++high;
    }
    return count;
}
long long int substrCount (string &s, int k) {
    return substrCountUtils(s, k) - substrCountUtils(s, k-1);
}
// Find two numbers occuring odd number of times -- coding ninjas

// Time complexity O(n)
// Space complexity O(n)
vector<int> twoOddNum(vector<int> arr){
    unordered_map<int, int>mp;
    for(const int val:arr) {
        mp[val]++;
    }
    vector<int> ans;
    for(const pair<int, int> p:mp) {
        if(p.second%2==1) {
            ans.push_back(p.first);
            if(ans.size()==2) {
                break;
            }
        }
    }
    if(ans[0]<ans[1]) {
        ans[0] = (ans[0]^ans[1]);
        ans[1] = (ans[0]^ans[1]);
        ans[0] = (ans[0]^ans[1]);
    }
    return ans;
}

// Time complexity O(n)
// Space complexity O(n)
vector<int> twoOddNum(vector<int> arr) {
    int xor3 = 0;
    for(const int val:arr) {
        xor3 ^= val;
    }
    int rightMostBit = (xor3 & ((~xor3)+1));
    int xor1 = 0, xor2 = 0;
    for(const int val:arr) {
        if(rightMostBit&val) {
            xor1 ^= val; 
        }
        else {
            xor2 ^= val;
        }
    }
    return xor1 < xor2 ? vector<int>{xor2, xor1} : vector<int>{xor1, xor2};
}
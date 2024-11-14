// Solution 1
// Easy to understand
// Time complexity O(nlogn)
// Space complexity O(n)

bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize!=0) return false;
    map<int, int> hash;
    for(int i=0; i<n; ++i) {
        hash[hand[i]]++;
    }
    int len = n / groupSize;
    for(int i=0; i<len; ++i) {
        int val = hash.begin()->first;
        hash[val]--;
        if(hash[val]==0) {
            hash.erase(hash.begin());
        }
        for(int j=1; j<groupSize; ++j) {
            ++val;
            if(hash[val]==0) {
                return false;
            }
            else {
                hash[val]--;
                if(hash[val]==0) {
                    hash.erase(val);
                }
            }
        }
    }
    return true;
}

// Solution 2
// Time complexity O(nlogn)
// Space complexity O(n)
bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();
    if(n % groupSize!=0) return false;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> hash;
    for(int i=0; i<n; ++i) {
        hash[hand[i]]++;
        pq.push(hand[i]);
    }
    int len = n / groupSize;
    for(int i=0; i<len; ++i) {
        while(hash[pq.top()]==0) {
            pq.pop();
        }
        int val = pq.top();
        pq.pop();
        hash[val]--;
        for(int j=1; j<groupSize; ++j) {
            ++val;
            if(hash[val]==0) {
                return false;
            }
            else {
                hash[val]--;
            }
        }
    }
    return true;
}
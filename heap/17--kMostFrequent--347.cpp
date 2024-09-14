class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(pair<int, int> p : freq) {
            minHeap.push(make_pair(p.second, p.first));
            if(minHeap.size() > k) minHeap.pop();
        }
        vector<int> ans(k);
        // int index = 0;
        int idx = k-1;
        while(!minHeap.empty()) {
            // this will give low frequency element to high frequence element
            // ans[index++] = minHeap.top().second;
            // this will give high frequency element to low frequence element
            ans[idx--] = minHeap.top().second;
            minHeap.pop();
        }
        return ans;
    }
};
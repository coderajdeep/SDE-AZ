// Time complexity O(Nlogk) + O(nlogk) where N --> total elements in stream
class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    void clearPQ() {
        while(!pq.empty()) pq.pop();
    }
public:
    KthLargest(int k, vector<int>& nums) {
        clearPQ();
        K = k;
        for(int num : nums) {
            pq.push(num);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K) pq.pop();
        // this will not occure
        if(pq.empty()) return -1;
        return pq.top();
    }
};
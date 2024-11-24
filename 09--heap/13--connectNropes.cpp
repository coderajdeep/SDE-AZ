// Time complexity O(2*nlogn)
// Space complexity O(n)
long long minCost(vector<long long>& arr) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(long long num : arr) {
        pq.push(num);
    }
    long long cost = 0;
    while(pq.size()>=2) {
        long long len1 = pq.top();
        pq.pop();
        long long len2 = pq.top();
        pq.pop();
        long long len = (len1 + len2);
        cost += len;
        pq.push(len);
    }
    return cost;
}
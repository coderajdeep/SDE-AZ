// Last Stone Weight -- leetcode 1046
// Time complexity O(nlogn)
// Space complexity O(n)
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;
    for(int stone : stones) {
        maxHeap.push(stone);
    }
    while(maxHeap.size()>=2) {
        int y = maxHeap.top();
        maxHeap.pop();
        int x = maxHeap.top();
        maxHeap.pop();
        if(x != y) maxHeap.push(y-x);
    }
    return maxHeap.empty() ? 0 : maxHeap.top();
}
// Median in data stream -- leetcode 295
// Time complexity O(NlogN)
// Space complexity O(N)
class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    void clearMinMaxHeap() {
        while(!minHeap.empty()) minHeap.pop();
        while(!maxHeap.empty()) maxHeap.pop();
    }
    int size;
public:
    MedianFinder() {
        clearMinMaxHeap();
    }
    
    void addNum(int num) {
        // This condition should be on top
        if(maxHeap.empty()) {
            maxHeap.push(num);
        }
        else if(maxHeap.size()==minHeap.size()) {
            // maxHeap and minHeap size > 0
            int minHeapTop = minHeap.top();
            if(num > minHeapTop) {
                maxHeap.push(minHeapTop);
                minHeap.pop();
                minHeap.push(num);
            }
            else {
                maxHeap.push(num);
            }
        }
        else {
            // here maxHeap.size() > minHeap.size()
            // Here minHeap.size() can be zero
            int maxHeapTop = maxHeap.top();
            if(num > maxHeapTop) {
                minHeap.push(num);
            }
            else {
                minHeap.push(maxHeapTop);
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }
        else {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
    }
};
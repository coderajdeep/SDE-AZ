// Time complexity O(logn)
// Space complexity O(1) -- Inerative approach
// Space complexity O(logn) -- Recursive approach
void heapify(int index, int n, vector<int> &heap) {
    int largest, L, R;
    while(index<n) {
        largest = index;
        L = 2*index+1;
        R = 2*index+2;
        if(L<n && heap[largest]<heap[L]) largest = L;
        if(R<n && heap[largest]<heap[R]) largest = R;
        if(largest != index) {
            swap(heap[index], heap[largest]);
            index = largest;
        }
        else {
            break;
        }
    }
}

void heapify_(int index, int n, vector<int> &heap) {
    int largest = index, L = 2*index+1, R = 2*index+2;
    if(L<n && heap[largest]<heap[L]) largest = L;
    if(R<n && heap[largest]<heap[R]) largest = R;
    if(largest != index) {
        swap(heap[index], heap[largest]);
        heapify_(largest, n, heap);
    }
}

int pop(vector<int> &heap) {
    // Write you code here.
    int n = heap.size();
    if(n==0) return -1;
    int top = heap.front();
    swap(heap[0], heap[n-1]);
    heap.pop_back();
    n -= 1;
    heapify_(0, n, heap);
    return top;
}

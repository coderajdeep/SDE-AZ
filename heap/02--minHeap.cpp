// Using vector
// heapify : Time O(logn), Space O(1)
// Insert : Time O(logn), Space O(1)
// Extract Min : Time O(logn), Space O(1)
// Delete in Particular Index : Time O(logn), Space O(1)
class minHeap {
private:
    vector<int> heap;
    void heapify(int index, int n, vector<int> &heap) {
        int smallest, L, R;
        while(index<n) {
            smallest = index;
            L = 2*index+1;
            R = 2*index+2;
            if(L<n && heap[smallest]>heap[L]) smallest = L;
            if(R<n && heap[smallest]>heap[R]) smallest = R;
            if(smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }    
public:
    
    // Constructor for the class.
    minHeap(int n) {
        heap.clear();
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        int n = heap.size();
        if(n==0) return -1;
        int top = heap[0];
        swap(heap[0], heap[n-1]);
        heap.pop_back();
        if(n==1) return top;
        --n;
        heapify(0, n, heap);
        return top;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        int n = heap.size();
        if(ind>=n) return;
        heap[ind] = INT_MIN;
        while((ind-1)/2 >=0 && heap[(ind-1)/2]>heap[ind]) {
            swap(heap[ind], heap[(ind-1)/2]);
            ind = (ind-1)/2;
        }
        swap(heap[0], heap[n-1]);
        heap.pop_back();
        heapify(0, n-1, heap);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        heap.push_back(val);
        int index = heap.size()-1;
        while((index-1)/2 >=0 && heap[(index-1)/2]>heap[index]) {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
};

// using array
class minHeap {
private:
    int* heap;
    int cap;
    int size;
    void heapify(int index, int n, int *heap) {
        int smallest, L, R;
        while(index<n) {
            smallest = index;
            L = 2*index+1;
            R = 2*index+2;
            if(L<n && heap[smallest]>heap[L]) smallest = L;
            if(R<n && heap[smallest]>heap[R]) smallest = R;
            if(smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }    
public:
    
    // Constructor for the class.
    minHeap(int N) {
        cap = N;
        heap = new int[cap];
        size = 0;
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        if(size==0) return -1;
        int top = heap[0];
        swap(heap[0], heap[size-1]);
        --size;
        if(size==0) return top;
        heapify(0, size, heap);
        return top;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if(ind>=size) return;
        heap[ind] = INT_MIN;
        while((ind-1)/2 >=0 && heap[(ind-1)/2]>heap[ind]) {
            swap(heap[ind], heap[(ind-1)/2]);
            ind = (ind-1)/2;
        }
        swap(heap[0], heap[size-1]);
        size--;
        heapify(0, size-1, heap);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        ++size;
        heap[size-1] = val;
        int index = size-1;
        while((index-1)/2 >=0 && heap[(index-1)/2]>heap[index]) {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
};


// Geeks
// Binary Heap operation
//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    if(heap_size==0) return -1;
    int ans = harr[0];
    swap(harr[0], harr[heap_size-1]);
    --heap_size;
    MinHeapify(0);
    return ans;
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    if(heap_size==0 || i>=heap_size) return;
    decreaseKey(i, INT_MIN);
    extractMin();
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    harr[heap_size++] = k;
    int index = heap_size - 1;
    while(index>0 && harr[parent(index)]>harr[index]) {
        swap(harr[parent(index)], harr[index]);
        index = parent(index);
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
// https://ide.geeksforgeeks.org/online-cpp14-compiler/d5b842b7-78f1-4659-bc67-1ae685cbe422
// https://www.youtube.com/watch?v=RU08pp_VPSs&list=PLEJXowNB4kPyP2PdMhOUlTY6GrRIITx28
// *** Important points ***

// O based indexing
// parent --> index
// left child --> 2*index + 1
// right child --> 2*index + 2

// node index --> idx
// parent --> (idx-1)/2

// In complete binary tree
// Total nodes --> n
// In 0 based indexing
// internal nodes --> [0 -- ((n/2)-1)]
// leaf nodes --> [(n/2) -- (n-1)]
// *** last internal is the parent of last leaf node ***

// If we want to implement heapify algorithm on a particular index, 
// then left and right subtree needs to follow the heap property
// to build a heap, we need to implement heapify algorithm only on internals nodes
// i.e from (n/2)-1 index to 0 index

// If we want non-decreasing order heap short then we need to use maxHeap

int parent(int index) {
    return (index-1)/2;
}

// min heap
// Time complexity O(logn)
// Space complexity O(logn)
void heapify_recursive_min(int index, int n, vector<int> &arr) {
    int smallest = index, left = (2*index + 1), right = (2*index + 2);
    if(left<n && arr[smallest]>arr[left]) {
        smallest = left;
    }
    if(right<n && arr[smallest]>arr[right]) {
        smallest = right;
    }
    if(smallest != index) {
        swap(arr[smallest], arr[index]);
        heapify_recursive_min(smallest, n, arr);
    }
}

// Time complexity O(logn)
// Space complexity O(1)
void heapify_iterative_min(int index, int n, vector<int> &arr) {
    while(index<n) {
        int smallest = index, left = (2*index + 1), right = (2*index + 2);
        if(left<n && arr[smallest]>arr[left]) {
            smallest = left;
        }
        if(right<n && arr[smallest]>arr[right]) {
            smallest = right;
        }
        if(smallest == index) {
            break;
        }
        swap(arr[index], arr[smallest]);
        index = smallest;
    }
}

// Time complexity O(n) (Mathematical proof is available)
// Space complexity O(1) (if using iterative heapify)
void buildHeapMin(int n, vector<int> &arr) {
    int start = (n/2)-1;
    for(int i=start; i>=0; --i) {
        heapify_iterative_min(i, n, arr);
        // heapify_recursive_min(i, n, arr);
    }
}

// Time complexity O(logn)
// Space complexity O(1)
int extractMin(int n, vector<int> &arr) {
    if(n==0) return -1;
    int minElement = arr[0];
    arr[0] = arr[n-1];
    arr.pop_back();
    n = arr.size(); // n = n-1
    heapify_iterative_min(0, n, arr);
    return minElement;
}

// Time complexity O(logn)
// Space complexity O(1)
void insertInMinHeap(int val, vector<int> &arr) {
    arr.push_back(val);
    int n = arr.size();
    if(n==1) return;
    int index = n-1;
    int par = parent(index);
    while(index>0 && arr[index]<arr[par]) {
        swap(arr[index], arr[par]);
        index = par;
        par = parent(index);
    }
}

// Time complexity O(nlogn)
// Space complexity O(1)
// Non-increasing order
void heapSortMin(vector<int> &arr) {
    int n = arr.size();
    buildHeapMin(n, arr);
    for(int i=n-1; i>=1; --i) {
        swap(arr[0], arr[i]);
        heapify_iterative_min(0, i, arr);
    }
}

// max heap
// in cpp stl, priority queue is by default max heap
// Time complexity O(logn)
// Space complexity O(logn)
void heapify_recursive_max(int index, int n, vector<int> &arr) {
    int largest = index, left = (2*index + 1), right = (2*index + 2);
    if(left<n && arr[largest]<arr[left]) {
        largest = left;
    }
    if(right<n && arr[largest]<arr[right]) {
        largest = right;
    }
    if(largest != index) {
        swap(arr[largest], arr[index]);
        heapify_recursive_max(largest, n, arr);
    }
}

// Time complexity O(logn)
// Space complexity O(1)
void heapify_iterative_max(int index, int n, vector<int> &arr) {
    while(index<n) {
        int largest = index, left = (2*index + 1), right = (2*index + 2);
        if(left<n && arr[largest]<arr[left]) {
            largest = left;
        }
        if(right<n && arr[largest]<arr[right]) {
            largest = right;
        }
        if(largest == index) {
            break;
        }
        swap(arr[index], arr[largest]);
        index = largest;
    }
}

// Time complexity O(n) (Mathematical proof is available)
// Space complexity O(1) (if using iterative heapify)
void buildHeapMax(int n, vector<int> &arr) {
    int start = (n/2)-1;
    for(int i=start; i>=0; --i) {
        heapify_iterative_max(i, n, arr);
        // heapify_recursive_max(i, n, arr);
    }
}

// Time complexity O(logn)
// Space complexity O(1)
int extractMax(int n, vector<int> &arr) {
    if(n==0) return -1;
    int maxElement = arr[0];
    arr[0] = arr[n-1];
    arr.pop_back();
    n = arr.size(); // n = n-1
    heapify_iterative_max(0, n, arr);
    return maxElement;
}

// Time complexity O(logn)
// Space complexity O(1)
void insertInMaxHeap(int val, vector<int> &arr) {
    arr.push_back(val);
    int n = arr.size();
    if(n==1) return;
    int index = n-1;
    int par = parent(index);
    while(index>0 && arr[index]>arr[par]) {
        swap(arr[index], arr[par]);
        index = par;
        par = parent(index);
    }
}

// Time complexity O(nlogn)
// Space complexity O(1)
// Non-decreasing order
void heapSortMax(vector<int> &arr) {
    int n = arr.size();
    buildHeapMax(n, arr);
    for(int i=n-1; i>=1; --i) {
        swap(arr[0], arr[i]);
        heapify_iterative_max(0, i, arr);
    }
}

void printArray(vector<int> &arr) {
    for(int x:arr) {
        cout<<x<<" ";
    }
    cout<<endl;
}
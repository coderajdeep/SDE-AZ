// Min Heap to max Heap
// Time complexity O(nlogn)
// Space complexity O(n)
void push(int value, vector<int> &heap) {
	heap.push_back(value);
	int index = heap.size()-1;
	if(index==0) return;
	while((index-1)/2>=0 && heap[index]>heap[(index-1)/2]) {
		swap(heap[index], heap[(index-1)/2]);
		index = (index-1)/2;
	}
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	vector<int> heap;
	for(int i=0; i<n; ++i) push(arr[i], heap);
	return heap;
}


// Build heap
// Time complexity O(n)
// Space complexity O(1) -- modifying given array
void heapify(int index, int n, vector<int> &heap) {
	while(index<n) {
		int largest = index;
		int L = 2*index+1;
		int R = 2*index+2;
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

vector<int>MinToMaxHeap(int n, vector<int>&arr) {
	int nonLeafLastIndex = (n/2-1);
	for(int i=nonLeafLastIndex; i>=0; --i) {
		heapify(i, n, arr);
	}
	return arr;
}
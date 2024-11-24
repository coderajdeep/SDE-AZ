// Selection Sort
// Time complexity O(n^2)
// Space complexity O(1)
void selectionSort(vector<int>&arr) {
    int n = arr.size();
    for(int i=0; i<n-1; ++i) {
        int smallestIndex = i;
        for(int j=i+1; j<n; ++j) {
            if(arr[smallestIndex] > arr[j]) {
                smallestIndex = j;
            }
        }
        swap(arr[i], arr[smallestIndex]);
    }
}
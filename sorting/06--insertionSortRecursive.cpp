// Recursive Insertion Sort
// Time complexity O(n^2)
// Space complexity O(n) [Recursive stack space]

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n)
{
    bool isSorted = true;
    for(int i=0; i<n-1; ++i) {
        if(arr[i]>arr[i+1]) {
            swap(arr[i], arr[i+1]);
            isSorted = false;
        }
    }
    if(isSorted) return;
    insertionSort(arr, n-1);
}
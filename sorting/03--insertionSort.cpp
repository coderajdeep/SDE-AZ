// Insertion Sort
// Time complexity O(n^2)
// Space complexity O(1)

// We need to track if the i-th elemnt is the current position or not

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; ++i) {
        for(int j=i; j>=0; --j) {
            if(arr[j-1]>arr[j]) {
                swap(arr[j-1], arr[j]);
            }
        }
    }
}
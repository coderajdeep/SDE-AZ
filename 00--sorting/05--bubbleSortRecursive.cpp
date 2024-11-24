// Recursive Bubble Sort
// Time complexity O(n^2)
// Space complexity O(n) [Recursive stack space]
void bubbleSort(vector<int>& arr, int n) 
{
    bool isSorted = true;
    for(int i=0; i<n-1; ++i) {
        if(arr[i]>arr[i+1]) {
            swap(arr[i], arr[i+1]);
            isSorted = false;
        }
    }
    if(isSorted) return;
    bubbleSort(arr, n-1);
}
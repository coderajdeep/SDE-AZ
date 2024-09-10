// Bubble sort
// Time complexity O(n^2)
// Space complexity O(1)

// We need to put the largest element on the last and need to reduce the end
void bubbleSort(vector<int>& arr, int n) 
{
    for(int i=n-1; i>=1; --i) {
        bool isSorted = true;
        for(int j=0; j<i; ++j) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if(isSorted) break;
    }
}
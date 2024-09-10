// Check if an array is Max Heap or not
// Time complexity O(n)
// Space complexity O(logH)
bool isMaxHeapUtils(int index, int n, int *arr) {
    // if index is the leaft node
    if(index>=(n/2)) return true;
    int L = 2*index + 1;
    int R = 2*index + 2;
    // check if the root element is greater than or equal to the left and right node or not 
    // as well as recursively check the same thing for left and right subtree
    return (arr[index]>=arr[L] && arr[index]>=arr[R] && isMaxHeapUtils(L, n, arr) && isMaxHeapUtils(R, n, arr));
}
bool isMaxHeap(int arr[], int n)
{
    return isMaxHeapUtils(0, n, arr);
}


// Iterative approach
// Time complexity O(n)
// Space complexity O(1)
bool isMaxHeap(int arr[], int n) {
    int lastNonLeafNodeIndex = (n/2)-1;
    for(int i=0; i<=lastNonLeafNodeIndex; ++i) {
        int L = 2*i + 1;
        int R = 2*i + 2;
        if(arr[L]>arr[i] || arr[R]>arr[i]) return false;
    }
    return true;
}
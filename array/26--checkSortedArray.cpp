// 26
// Check if and array is sorted or not
// https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957

int isSorted(int n, vector<int> a) {
    if(n<=1) return 1;
    for(int i=1; i<n; ++i) {
        if(a[i]<a[i-1]) return 0;
    }
    return 1;
}
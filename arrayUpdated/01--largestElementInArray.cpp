#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // given 1<= n <=10^5
    int largest = arr[0];
    for(int i=1; i<n; ++i) {
        if(largest<arr[i]) {
            largest = arr[i];
        }
    }
    return largest;
}

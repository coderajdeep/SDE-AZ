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

// Using STL
// https://www.geeksforgeeks.org/problems/largest-element-in-array4009/0
int largest(vector<int> &arr) {
    return *max_element(arr.begin(), arr.end());
}

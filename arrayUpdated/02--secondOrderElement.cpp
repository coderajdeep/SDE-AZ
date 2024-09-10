// Time complexity O(n)
// Space complexity O(n)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int largest1 = INT_MIN, largest2 = INT_MIN, smallest1 = INT_MAX, smallest2 = INT_MAX;
    for(int i=0; i<n; ++i) {
        if(a[i]>largest1) {
            largest2 = largest1;
            largest1 = a[i];
        }
        // a[i]!=largest1
        // this will also work
        else if(a[i]>largest2 && a[i]<largest1) {
            largest2 = a[i];
        }
        if(smallest1>a[i]) {q
            smallest2 = smallest1;
            smallest1 = a[i];
        }
        // a[i]!=smallest1
        // this will also work 
        else if(smallest2>a[i] && smallest1<a[i]) {
            smallest2 = a[i];
        }
    }
    return vector<int> {largest2, smallest2};
}

// Time complexity O(n)
// Space complexity O(n)
// Third Maxmimum element
int thirdLargest(int a[], int n){
    if(n<3) return -1;
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    for(int i=0; i<n; ++i) {
        if(a[i]>max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i]>max2 && a[i]<max1) {
            max3 = max2;
            max2 = a[i];
        }
        else if(a[i]>max3 && a[i]<max2) {
            max3 = a[i];
        }
    }
    return max3;
}
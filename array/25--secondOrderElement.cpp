// https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960
// Second largest and second smallest element

// Time complexity O(n)
// Space complexity O(1)
vector<int> getSecondOrderElements(int n, vector<int>& arr) {
    int largest = INT_MIN, secondLargest = INT_MIN;
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for(int i=0; i<n; ++i) {
        if(largest<arr[i]) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if((secondLargest<arr[i]) && (largest>arr[i])) {
            secondLargest = arr[i];
        }
        if(smallest>arr[i]) {
            secondSmallest = smallest;
            smallest = arr[i];
        }
        else if((secondSmallest>arr[i]) &&(smallest<arr[i])) {
            secondSmallest = arr[i];
        }
    }
    return {secondLargest, secondSmallest};
}
// Rotation count in rotated sorted array
// https://www.codingninjas.com/studio/problems/rotation_7449070?

// Time complexity O(logn)
// Space complexity O(1)
int findKRotation(vector<int> &arr){
    int minIndex = -1;
    int n = arr.size();
    int low = 0, high = n-1, mid;
    while(low<=high) {
        mid = low + (high-low)/2;
        if(arr[low]<=arr[mid]) {
            if(minIndex==-1) {
                minIndex = low;
            }
            else {
                minIndex = arr[low]<arr[minIndex] ? low : minIndex;
            }
            low = mid+1;
        }
        else {
            if(minIndex==-1) {
                minIndex = mid;
            }
            else {
                minIndex = arr[mid]<arr[minIndex] ? mid : minIndex;
            }
            high = mid-1;
        }
    }
    return minIndex;
}
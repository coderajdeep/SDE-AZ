// 28
// Left Rotate by once -- Coding Ninjas
// https://www.codingninjas.com/studio/problems/left-rotate-an-array-by-one_5026278


// Time complexity O(n)
// Space complexity O(1)
vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];
    for(int i=0; i<n-1; ++i) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
    return arr;
}

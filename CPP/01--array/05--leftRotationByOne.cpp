// Time complexity O(n)
// Space Complexity O(1)

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
vector<int> rotateArray(vector<int>& arr, int n) {
    for(int i=0; i<n-1; ++i) {
        swap(arr[i], arr[i+1]);
    }
    return arr;
}

// For finding right rotation by once, we can swap from n-1 to 1 index
// Time complexity O(n)
// Space Complexity O(1)
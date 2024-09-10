// Right Rotation or clockwise rotation of an array by K -- leetcode 189
// Time complexity O(2*n)
// Space complexity O(1)

void swapNumbers(int& a, int& b) {
    a = (a+b);
    b = (a-b);
    a = (a-b);
}
void reverseArray(int start, int end, vector<int>& nums) {
    while(start<end) {
        swapNumbers(nums[start++], nums[end--]);
    }
}
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n==k || n==1) return;
    if(k>n) k = (k % n);
    reverseArray(0, n - k - 1, nums);
    reverseArray(n - k, n - 1, nums);
    reverseArray(0, n - 1, nums);
}

// Clockwise or right rotation using STL
// Time complexity O(2*n)
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(k>=n) k = k % n;
    reverse(nums.begin(), nums.end()-k);
    reverse(nums.begin()+n-k, nums.end());
    reverse(nums.begin(), nums.end());
}


// Left Rotation or anti clockwise rotation of an array by K -- coding ninjas
// Time complexity O(2*n)
// Space complexity O(1)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(vector<int>& arr, int start, int end) {
    while(start<end) {
        swap(arr[start++], arr[end--]);
    }
}

vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    if(n<=k) return arr;
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
    return arr;
}
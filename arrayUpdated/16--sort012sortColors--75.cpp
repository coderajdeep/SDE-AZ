// 5
// sort 0 1 2 - sort colors
// leetcode 75

// Best approach
// Duch national flag algo
// Time complexity O(n)
// Space complexity O(1)
// Single traversal
// Best approach
void swap(int& a, int& b) {
    int temp = a;
    a = b; 
    b = temp;
}
void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<=high) {
        if(nums[mid]==0) {
            swap(nums[mid++], nums[low++]);
        }
        else if(nums[mid]==1) {
            mid++;
        }
        else if(nums[mid]==2) {
            swap(nums[mid], nums[high--]);
        }
    }
}

// Time complexity O(2*n) ~ O(n)
// Space complexity O(1)
void sortColors(vector<int>& nums) {
    int one, two, three;
    one = two = three = 0;
    int n = nums.size();
    for(int i=0; i<n; ++i) {
        if(nums[i]==0) ++one;
        else if(nums[i]==1) ++two;
        else if(nums[i]==3) ++three;
    }
    for(int i=0; i<one; ++i) {
        nums[i] = 0;
    }
    int second = one + two;
    for(int i=one; i<second; ++i) {
        nums[i] = 1;
    }
    for(int i=second; i<n; ++i) {
        nums[i] = 2;
    }
}
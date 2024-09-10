// Next Permutation -- leetcode 31


// Time complexity O(n)
// Space complexity O(1)
void nextPermutation(vector<int>& nums) {
    int n = nums.size(), pivot = -1;
    for(int i=n-2; i>=0; --i) {
        if(nums[i]<nums[i+1]) {
            pivot = i;
            break;
        }
    }
    if(pivot == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i=n-1; i>pivot; --i) {
        if(nums[pivot]<nums[i]) {
            swap(nums[pivot], nums[i]);
            break;
        }
    }
    reverse(nums.begin()+pivot+1, nums.end());
}

// Here we are not using STL
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int start, int end, vector<int>& nums) {
    while(start<end) {
        swap(nums[start++], nums[end--]);
    }
}
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = -1;
    for(int i=n-2; i>=0; --i) {
        if(nums[i]<nums[i+1]) {
            index = i;
            break;
        }
    }
    if(index==-1) {
        reverseArray(0, n-1, nums);
        return;
    }
    for(int i=n-1; i>index; --i) {
        if(nums[i]>nums[index]) {
            swap(nums[index], nums[i]);
            break;
        }
    }
    reverseArray(index+1, n-1, nums);
}

// Time complexity O(nlogn)
// Space complexity O(n)
class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void reverse(vector<int>& arr, int start, int end) {
        while(start<end) {
            swap(arr[start++], arr[end--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;
        vector<int> lastElements;
        lastElements.reserve(n);
        for(int i=n-1; i>=1; --i) {
            lastElements.push_back(nums[i]);
            if(nums[i-1]<nums[i]) {
                pivot = i-1;
                break;
            }
        }
        if(pivot==-1) {
            reverse(nums, 0, n-1);
            return;
        }
        sort(lastElements.begin(), lastElements.end());
        int index = upper_bound(lastElements.begin(), lastElements.end(), nums[pivot]) - lastElements.begin();
        int temp = lastElements[index];
        lastElements[index] = nums[pivot];
        nums[pivot] = temp;
        int arrIndex = pivot+1;
        for(int element:lastElements) {
            nums[arrIndex++] = element;
        }
    }
};
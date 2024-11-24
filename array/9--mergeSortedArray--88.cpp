// 9
// leetcode - 88
// Merge two sorted array
// Time complexity O(n+m)
// Space complexity O(n+m)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int nums[n+m];
    int index = 0, i = 0, j = 0;
    while(i<m && j<n) {
        if(nums1[i]<nums2[j]) {
            nums[index++] = nums1[i++];
        }
        else {
            nums[index++] = nums2[j++];
        }
    }
    while(i<m) {
        nums[index++] = nums1[i++];
    }
    while(j<n) {
        nums[index++] = nums2[j++];
    }
    for(int i=0; i<m; ++i) nums1[i] = nums[i];
    for(int i=m; i<(n+m); ++i) nums1[i] = nums[i];
}

// Time complexity O(nlogn + mlogm + n + m) ~ O(nlogn + mlogm)
// Space complexity O(1)
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j = 0;
    while(i>=0 && j<n) {
        if(nums1[i]>nums2[j]) {
            swap(nums1[i--], nums2[j++]);
        }
        else {
            break;
        }
    }
    sort(nums1.begin(), nums1.begin()+m);
    sort(nums2.begin(), nums2.end());
    const int size = m + n;
    for(int i=m; i<size; ++i) {
        nums1[i] = nums2[i-m];
    }
}
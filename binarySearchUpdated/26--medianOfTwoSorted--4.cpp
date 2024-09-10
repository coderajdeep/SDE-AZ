// Solution 1
// Time complexity O(n+m)
// Space complexity O(n+m)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0, k = 0;
    int s = (n+m);
    vector<int> arr(s);
    while(i<n && j<m) {
        if(nums1[i]<nums2[j]) {
            arr[k++] = nums1[i++];
        }
        else {
            arr[k++] = nums2[j++];
        }
    }
    while(i<n) {
        arr[k++] = nums1[i++];
    }
    while(j<m) {
        arr[k++] = nums2[j++];
    }
    return (s & 1) ? arr[s/2] : (arr[s/2] + arr[(s/2)-1])/2.0;
}

// Solution 2
// Time complexity O(n+m)
// Space complexity O(1)
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int i = 0, j = 0, k = 0;
    int s = (n + m);
    if (s == 1) {
        return n == 1 ? nums1[0] : nums2[0];
    }
    int ind1 = ((s / 2) - 1), ind2 = (s / 2), ans1, ans2, val;
    bool flag = true;
    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            val = nums1[i++];
        }
        else {
            val = nums2[j++];
        }
        if (k == ind1) ans1 = val;
        else if (k == ind2) ans2 = val;
        if (k >= ind2) {
            flag = false;
            break;
        }
        ++k;
    }
    while (i < n && flag) {
        if (k == ind1) ans1 = nums1[i];
        else if (k == ind2) ans2 = nums1[i];
        if (k >= ind2) break;
        ++k;
        ++i;
    }
    while (j < m && flag) {
        if (k == ind1) ans1 = nums2[j];
        else if (k == ind2) ans2 = nums2[j];
        if (k >= ind2) break;
        ++j;
        ++k;
    }
    return (s & 1) ? ans2 : (ans1 + ans2) / 2.0;
}


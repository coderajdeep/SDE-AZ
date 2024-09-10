// Time complexity O(nlogn)
// Space complexity O(1)
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1, j=0, k=m, size=(n+m);
    if(n==0) return;
    if(m==0 || nums1[m-1]<=nums2[0]) {
        while(k<size && j<n) {
            nums1[k++] = nums2[j++];
        }
        return;
    }
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
    k = m, j = 0;
    while(k<size && j<n) {
        nums1[k++] = nums2[j++];
    }
}
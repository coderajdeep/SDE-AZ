// Similar to longest subarray having K distinct element
// Time complexity O(n)
// Space complexity O(n)
class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int n = arr.size(), left = 0, right = 0, total = 0;
        unordered_map<int, int> umap;
        while(right<n) {
            umap[arr[right]]++;
            while(left<=right && umap.size()>2) {
                umap[arr[left]]--;
                if(umap[arr[left]]==0) {
                    umap.erase(arr[left]);
                }
                ++left;
            }
            total = max(total, right-left+1);
            ++right;
        }
        return total;
    }
};
// Time complexity O(n)
// Space complexity O(1)

int subarraysXor(vector<int> &arr, int x) {
    int xr = 0, count = 0, n = arr.size();
    unordered_map<int, int> um;
    // this is for handling the subarray starting from index 0 to index i
    um[0] = 1;
    for(int i=0; i<n; ++i) {
        xr ^= arr[i];
        int new_xor = xr ^ x;
        auto it = um.find(new_xor);
        if(it != um.end()) {
            count += it->second;
        }
        um[xr]++;
    }
    return count;
}
// First Missing Positive Number -- leetcode 41
// Time complexity O(n)
// Space complexity O(n)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> uset;
    for(int num : nums) uset.insert(num);
    for(int posNum=1; posNum<=n; ++posNum) {
        if(uset.find(posNum) == uset.end()) {
            return posNum;
        }
    }
    return n+1;
}
// Time complexity O(n^2)
// Space complexity O(1)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int posNum=1; posNum<=n; ++posNum) {
        bool isPresent = false;
        for(int j=0; j<n; ++j) {
            if(nums[j] == posNum) {
                isPresent = true;
                break;
            }
        }
        if(!isPresent) return posNum;
    }
    return n+1;
}
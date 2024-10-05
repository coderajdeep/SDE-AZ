// Longest Consecutive Sequence -- leetcode 128
// Solution 1
// Time complexity O(nlogn)
// Space complexity O(1)

// *** Array can be empty and array can have duplicate numbers
// Need to think about this for below solution
int longestConsecutive(vector<int>& nums) {
    int n = nums.size(), lastSmallest = INT_MIN, count, maxCount = INT_MIN;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; ++i) {
        if(lastSmallest+1 == nums[i]) {
            ++count;
        }
        else if(lastSmallest != nums[i]){
            count = 1;
        }
        lastSmallest = nums[i];
        maxCount = max(count, maxCount);
    }
    return maxCount == INT_MIN ? 0 : maxCount;
}

// Solution 2
// Time complexity O(n)
// Space complexity O(n)
// Clean solution
class Solution{
    public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> uset;
        for(int i=0; i<N; ++i) {
            uset.insert(arr[i]);
        }
        int maxLen = 1;
        for(int i=0; i<N; ++i) {
            if(uset.find(arr[i]-1) == uset.end()) {
                int len = 1, next = arr[i]+1;
                while(uset.find(next) != uset.end()) {
                    ++len;
                    ++next;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
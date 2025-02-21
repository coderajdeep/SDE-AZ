// Shortest Job First
// Time complexity O(n*logn)
// Space complexity O(1)

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long totalWatingTime = 0, waitingTime = 0;
        for(int i=0; i<(n-1); ++i) {
            waitingTime += bt[i];
            totalWatingTime += waitingTime;
        }
        return totalWatingTime/n;
    }
};
// Max point you can obtain from cards -- leetcode 1423

// Time complexity O(2*k)
// Time complexity O(1)
int maxScore(vector<int>& cardPoints, int k) {
    int lsum = 0, rsum = 0, ans = 0, n = cardPoints.size();
    for(int i=0; i<k; ++i) {
        lsum += cardPoints[i];
    }
    if(k==n) return lsum;
    ans = max(ans, lsum);
    for(int i=0; i<k; ++i) {
        int left = k-1-i;
        int right = n-1-i;
        lsum -= cardPoints[left];
        rsum += cardPoints[right];
        ans = max(ans, lsum+rsum);
    }
    return ans;
}
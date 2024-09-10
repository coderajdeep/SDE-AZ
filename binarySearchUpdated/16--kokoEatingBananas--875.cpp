// Koko eating bananas -- leetcode 875

// Time complexity O(log(max num in array) * (size of array)) + O(max in the array)
// Space complexity O(1)
int timeRequired(int k, vector<int> &piles) {
    int time = 0;
    for(int pile : piles) {
        time += (pile / k);
        if(pile % k != 0) {
            time += 1;
        }
    }
    return time;
}
int getMaxValue(int n, vector<int> &piles) {
    int val = INT_MIN;
    for(int pile : piles) {
        val = max(val, pile);
    }
    return val;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int low = 1, high = getMaxValue(n, piles), ans = 1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        int time = timeRequired(mid, piles);
        if(time<=h) {
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    return ans;
}